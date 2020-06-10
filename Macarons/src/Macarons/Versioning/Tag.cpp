#include "mrpch.h"
#include "Tag.h"

#include "Commit.h"

#include <git2.h>

namespace Macarons
{
	Tag::Tag(git_tag* tag) : m_Tag{ tag }
	{
	}

	Tag::Tag(Tag&& other) noexcept
	{
		m_Tag = std::move(other.m_Tag);
		other.m_Tag = nullptr;
	}

	Tag::~Tag()
	{
		git_tag_free(m_Tag);
	}

	std::string Tag::GetName() const
	{
		return git_tag_name(m_Tag);
	}

	std::string Tag::GetMessage() const
	{
		return git_tag_message(m_Tag);
	}

	Macarons::GitUser Tag::GetTagger() const
	{
		const git_signature* tagger = git_tag_tagger(m_Tag);
		
		GitUser user;
		user.Name = tagger->name;
		user.Email = tagger->email;

		return user;
	}

	static GitObjectType GetObjectType(git_object_t type)
	{
		switch (type)
		{
		case GIT_OBJECT_ANY:
			return GitObjectType::Any;

		case GIT_OBJECT_BLOB:
			return GitObjectType::Blob;

		case GIT_OBJECT_COMMIT:
			return GitObjectType::Commit;

		case GIT_OBJECT_INVALID:
			return GitObjectType::Invalid;

		case GIT_OBJECT_OFS_DELTA:
		case GIT_OBJECT_REF_DELTA:
			return GitObjectType::Delta;

		default:
			MR_CORE_ASSERT(false, "Git object type is not supported");
		}
	}

	GitObjectType Tag::GetTarget() const
	{
		return GetObjectType(git_tag_target_type(m_Tag));
	}
}