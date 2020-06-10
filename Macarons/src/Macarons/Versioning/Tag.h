#pragma once

#include "Repository.h"

struct git_tag;

namespace Macarons
{
	struct GitUser;

	class Tag
	{
	private:
		friend class Commit;

	private:
		Tag(git_tag* tag);

	public:
		Tag(Tag&&) noexcept;
		~Tag();

		std::string GetName() const;
		std::string GetMessage() const;
		GitUser GetTagger() const;

		GitObjectType GetTarget() const;

	private:
		git_tag* m_Tag;
	};
}