//
// Created by Ivo Georgiev on 10/29/15.
//

#ifndef CLUSTERING_CLUSTERINGTESTS_H
#define CLUSTERING_CLUSTERINGTESTS_H

#include "ErrorContext.h"

using namespace Testing;


// - - - - - - - - - Tests: class Point - - - - - - - - - -

// Smoketest: constructor, copy constructor, destructor
void test_point_smoketest(ErrorContext &ec);

// setValue, getValue, operator[]
void test_point_getsetelem(ErrorContext &ec, unsigned int numRuns);

// Copy constructor
void test_point_copying(ErrorContext &ec, unsigned int numRuns);

// operator=
void test_point_assignment(ErrorContext &ec, unsigned int numRuns); // TODO add test for self-assignment, add test for assignment to empty cluster

// operator==, operator!=
void test_point_equality(ErrorContext &ec, unsigned int numRuns);

// operator<, operator<=, operator>, operator>=
// (pseudo-lexicographic comparison)
void test_point_comparison(ErrorContext &ec, unsigned int numRuns);

// operator+=, operator-=, operator*=, operator/=
void test_point_CAO(ErrorContext &ec, unsigned int numRuns);

// operator+, operator-, operator*, operator/
void test_point_SAO(ErrorContext &ec, unsigned int numRuns);

// distanceTo
void test_point_distance(ErrorContext &ec, unsigned int numRuns);

// operator>>, operator<< (incl. exceptions)
void test_point_IO(ErrorContext &ec, unsigned int numRuns);



// - - - - - - - - - Tests: class Cluster - - - - - - - - - -

// Smoketest: constructor, copy constructor, destructor
void test_cluster_smoketest(ErrorContext &ec);

// add, remove, operator[]
void test_cluster_addremove(ErrorContext &ec, unsigned int numRuns);

// Inner class Move
void test_cluster_move(ErrorContext &ec, unsigned int numRuns);

// Copy constructor
void test_cluster_copying(ErrorContext &ec, unsigned int numRuns);

// operator=
void test_cluster_assignment(ErrorContext &ec, unsigned int numRuns);

// operator==, operator!=
void test_cluster_equality(ErrorContext &ec, unsigned int numRuns);

// operator+=, operator-=, different rhs
void test_cluster_CAO(ErrorContext &ec, unsigned int numRuns);

// operator+, operator-, different rhs
void test_cluster_SAO(ErrorContext &ec, unsigned int numRuns);

// Centroid
void test_cluster_centroid(ErrorContext &ec, unsigned int numRuns);

// Id
void test_cluster_id(ErrorContext &ec, unsigned int numRuns);

// Init element selection ("pickPoints")
void test_cluster_initselection(ErrorContext &ec, unsigned int numRuns);

// Scoring functions
void test_cluster_scoring(ErrorContext &ec, unsigned int numRuns);

// operator>>, operator<<
void test_cluster_IO(ErrorContext &ec, unsigned int numRuns);



// - - - - - - - - - Tests: class KMeans - - - - - - - - - -

// Smoketest: constructor, destructor, loading points
void test_kmeans_smoketest(ErrorContext &ec);

// operator<<
void test_kmeans_IO(ErrorContext &ec, unsigned int numRuns);

// Clustering score
void test_kmeans_score(ErrorContext &ec, unsigned int numRuns);

// K larger than number of points
void test_kmeans_toofewpoints(ErrorContext &ec, unsigned int numRuns);

// Check if scoring works with large points
void test_kmeans_largepoints(ErrorContext &ec, unsigned int numRuns);

// Large k, less than number of points
void test_kmeans_toomanyclusters(ErrorContext &ec, unsigned int numRuns); // TODO implement

#endif //CLUSTERING_CLUSTERINGTESTS_H
