#include "constraints_set.h"

void ConstraintsSet::addNodeConstraint(int i, int j, int time, int agentId) {
    nodeConstraints.insert(Constraint(i, j, time, agentId));
}

void ConstraintsSet::addGoalNodeConstraint(int i, int j, int time, int agentId) {
    goalNodeConstraints.insert(Constraint(i, j, time, agentId, -1, -1, true));
}

void ConstraintsSet::addEdgeConstraint(int i, int j, int time, int agentId, int prevI, int prevJ) {
    edgeConstraints.insert(Constraint(i, j, time, agentId, prevI, prevJ));
}

void ConstraintsSet::addConstraint(Constraint &constraint) {
    if (constraint.prev_i == -1) {
        if (constraint.goalNode) {
            goalNodeConstraints.insert(constraint);
        } else {
            nodeConstraints.insert(constraint);
        }
    } else {
        edgeConstraints.insert(constraint);
    }
}

ConstraintsSet ConstraintsSet::getAgentConstraints(int agentId) const {
    ConstraintsSet res;
    for (auto constraint : nodeConstraints) {
        if (constraint.agentId == agentId) {
            res.nodeConstraints.insert(constraint);
        }
    }
    for (auto constraint : edgeConstraints) {
        if (constraint.agentId == agentId) {
            res.edgeConstraints.insert(constraint);
        }
    }
    for (auto constraint : goalNodeConstraints) {
        if (constraint.agentId == agentId) {
            res.goalNodeConstraints.insert(constraint);
        }
    }
    return res;
}

bool ConstraintsSet::hasNodeConstraint(int i, int j, int time, int agentId) const {
    if (nodeConstraints.find(Constraint(i, j, time, agentId)) != nodeConstraints.end()) {
        return true;
    }
    auto constraint = goalNodeConstraints.lower_bound(Constraint(i, j, 0));
    return constraint != goalNodeConstraints.end() && constraint->i == i && constraint->j == j && constraint->time <= time;
}

bool ConstraintsSet::hasFutureConstraint(int i, int j, int time, int agentId) const {
    std::set<Constraint>::iterator constraint = nodeConstraints.lower_bound(Constraint(i, j, time));
    if (constraint != nodeConstraints.end() && constraint->i == i && constraint->j == j) {
        return true;
    }
    constraint = goalNodeConstraints.lower_bound(Constraint(i, j, time));
    return constraint != goalNodeConstraints.end() && constraint->i == i && constraint->j == j;
}

bool ConstraintsSet::hasEdgeConstraint(int i, int j, int time, int agentId, int prevI, int prevJ) const {
    return edgeConstraints.find(Constraint(i, j, time, agentId, prevI, prevJ)) != edgeConstraints.end();
}
