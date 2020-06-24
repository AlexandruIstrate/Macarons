#pragma once

#include "Reference.h"

#include <optional>

namespace Macarons
{
	class Commit;

	enum class BranchType
	{
		Local,
		Remote
	};

	struct GitUser
	{
		std::string Name;
		std::string Email;
	};

	class Branch : public Reference
	{
	private:
		friend class Repository;

	private:
		Branch(git_reference* ref, BranchType type, const Repository& repo);

	public:
		inline BranchType GetBranchType() const { return m_BranchType; }
		inline const Repository& GetRepository() const { return m_Repository; }

		std::string GetDisplayName() const;

		bool IsActive() const;
		bool IsTrackingRemote() const;

		std::optional<Branch> GetUpstream() const;
		void SetUpstream(const Branch& upstream);

		std::vector<Commit> GetCommits() const;
		Commit CreateCommit(const GitUser& author, std::string& message);

		void Reset(bool hard);

	private:
		BranchType m_BranchType;
		const Repository& m_Repository;
	};
}
