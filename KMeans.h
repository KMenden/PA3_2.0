#ifndef KELLEN_CSCI2312_PA2_KMEANS_H
#define KELLEN_CSCI2312_PA2_KMEANS_H
#include "Point.h"
#include "Cluster.h"
#include <string>
#include <vector>
#include <fstream>
//
using namespace Clustering;
class KMeans {



public:

    KMeans(unsigned int pointdemensionsvalue, int kvalue, std::string file ) : k(kvalue), pointdemensions(pointdemensionsvalue), __iFileName(file), score(0), __initCentroids(new Point *[k])
    {
        scorediff = SCORE_DIFF_THRESHOLD + 1;

        clusterarray.reserve(k);
        for (int i = 0; i < k; i++)
        {
            clusterarray.emplace_back(pointdemensions);
        }

        if (__iFileName != "") {
            std::ifstream csv(__iFileName);
            if (csv.is_open()) {    // TODO exception on failure
                csv >> clusterarray[0];
                csv.close();
            }
        }
        if(clusterarray[0].getSize() > 0)
        {
            clusterarray[0].pickPoints(k, __initCentroids);

            for (int i = 0; i < k; i++) {
                clusterarray[i].setCentroid(*__initCentroids[i]);
            }
        }
    };

    ~KMeans()
    {
      delete [] __initCentroids;
    }

    unsigned int pointdemensions;
    int k;
    static constexpr double SCORE_DIFF_THRESHOLD = 20;
    double betacv;
    std::string __iFileName;
    double scorediff;
    std::vector<Cluster> clusterarray;
    int score;
    Point **__initCentroids;

    double mindistance(Point &, Point );
    double computeClusteringScore();
    void run();
    double getScore() const { return score; }

    friend std::ostream &operator<<(std::ostream &os, const KMeans &kmeans);\

    Cluster &operator[](unsigned int u);
    const Cluster &operator[](unsigned int u) const;

};



#endif //KELLEN_CSCI2312_PA2_KMEANS_H
