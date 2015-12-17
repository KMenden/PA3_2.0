#include "KMeans.h"
#include "Point.h"
#include "Cluster.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

//
using namespace Clustering;
using namespace std;

double KMeans::mindistance(Point &point, Point centroid)
{

    double distance = point.distanceTo(centroid);
    return distance;
}

void KMeans::run()
{

    while (scorediff > SCORE_DIFF_THRESHOLD)
    {
        for (int i = 0; i < k; i++)
        {
            LNodePtr current = clusterarray[i].getheadpointer();
            double minimaldistance = 99999;
            while (current != nullptr)
            {
                bool checkswap = false;
                bool swap = false;
                int clusterindex = -1;
                for (int i2 = 0; i2 < k; i2++)
                {

                    double distance = mindistance(*(current->p), clusterarray[i2].getCentroid());
                    if (distance < minimaldistance)
                    {
                        minimaldistance = distance;
                        clusterindex = i2;
                        checkswap = true;
                    }

                }
                if (clusterindex != i && checkswap)
                {
                    Cluster::Move moveclusters(current->p, &clusterarray[i], &clusterarray[clusterindex]);
                    moveclusters.perform();
                    current = clusterarray[i].getheadpointer();
                    swap = true;
                }

                if (swap == false)
                {
                    current = current->next;
                }
                minimaldistance = 99999;
            }
        }

        for (int index = 0; index < k; index++)
        {
            if (!clusterarray[index].isCentroidValid())
            {
                clusterarray[index].computeCentroid();
            }
        }

        int betaCV = computeClusteringScore();

        scorediff = abs(score - betaCV);
        score = betaCV;
    }


}


double KMeans::computeClusteringScore()
{
        double dIn = 0;

        for (int index = 0; index < k; index++)
        {
            double sum = clusterarray[index].intraClusterDistance();
            dIn += sum;
        }

        double dOut = 0;

        int i = 0;
        int i2 = 1;

        while (i < k)
        {
            while (i2 < k)
            {
                double sum = interClusterDistance(clusterarray[i], clusterarray[i2]);
                dOut += sum;
                i2++;
            }
            i++;
            i2 = i + 1;
        }
        double pIn = 0;
        for (int index = 0; index < k; index++)
        {
            double sum = clusterarray[index].getClusterEdges();
            pIn += sum;
        }
        double pOut = 0;

        int cindex = 0;
        int cindex2 = 0;

        while (cindex < k)
        {
            while (cindex2 < k)
            {
                double sum = interClusterEdges(clusterarray[cindex], clusterarray[cindex2]);
                pOut += sum;
                cindex2++;
            }
            cindex++;
            cindex2 = i + 1;
        }
    if(dIn == 0 || pIn == 0 || dOut == 0 || pOut == 0)
    {
        return 0;
    }
    else
    {
        int computedscore = (dIn / pIn) / (dOut / pOut);

        return computedscore;
    }
}


std::ostream &operator<<(std::ostream &os, const KMeans &kmeans)
{
    ofstream output("results.txt");
        for (int i = 0; i < kmeans.k; i++)
        {
            output << kmeans.clusterarray[i];
        }
        for (int i = 0; i < kmeans.k; i++)
        {
            cout << kmeans.clusterarray[i];
        }
        output.close();

    return os;
}

Cluster& KMeans::operator[](unsigned int u)
{
    return clusterarray[u];
}
const Cluster& KMeans::operator[](unsigned int u) const
{
    return clusterarray[u];
}