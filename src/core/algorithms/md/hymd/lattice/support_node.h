#pragma once

#include "algorithms/md/hymd/lattice/lhs_specialization.h"
#include "algorithms/md/hymd/lattice/node_base.h"
#include "algorithms/md/hymd/md_lhs.h"

namespace algos::hymd::lattice {
class SupportNode : public NodeBase<SupportNode> {
public:
    using Specialization = LhsSpecialization;

    bool is_unsupported = false;

    static MdLhs const& GetLhs(Specialization::Unspecialized lhs) noexcept {
        return lhs;
    }

    bool ContainsGeneralizationOf(Specialization::Unspecialized) const noexcept {
        return is_unsupported;
    }

    SupportNode* AddOneUnchecked(model::Index child_array_index,
                                 model::md::DecisionBoundary bound) {
        return AddOneUncheckedBase(child_array_index, bound);
    }

    SupportNode(std::size_t children_number) : NodeBase<SupportNode>(children_number) {}
};
}  // namespace algos::hymd::lattice