#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"
#include <vector>
//
namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

//    struct LNode;
//    typedef LNode *LNodePtr;

    struct LNode {
        PointPtr p;
        LNodePtr next;
    };



    class Cluster {
        int size;
        LNodePtr points;
        bool __release_points;
        unsigned int __id;
        static unsigned int __idGenerator;
        Point __centroid;
        bool __centroidvalidity;
        unsigned int pointdimensions;

    public:
        Cluster() : size(0), points(nullptr), __id(generateid()), __centroid(pointdimensions = 5), __centroidvalidity(false) {};
        Cluster(unsigned int dimensions) : size(0), points(nullptr), __id(generateid()), pointdimensions(dimensions), __centroid(dimensions), __centroidvalidity(false) {};
        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);
        Cluster &operator=(const Cluster &);
        ~Cluster();

        class Move{
            PointPtr ptr;
            Cluster *to, *from;
        public:
            void perform();
            Move(const PointPtr &, Cluster *, Cluster *);
        };

        // Set functions: They allow calling c1.add(c2.remove(p));
        void add(const PointPtr &);
        const PointPtr &remove(const PointPtr &);

        // Overloaded operators

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster &);

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        // - Members
        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference

        Cluster &operator+=(const Point &rhs); // add point
        Cluster &operator-=(const Point &rhs); // remove point

        // Set-destructive operators (duplicate points in the space)
        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);

        static unsigned int generateid();
        unsigned int getId()const;

        int getSize();

        void setCentroid(const Point &);

        const Point getCentroid() const;

        void computeCentroid();

        void pickPoints(unsigned int k, PointPtr *pointArray);

        double intraClusterDistance() const;

        friend double interClusterDistance(const Cluster &c1, const Cluster &c2);

        int getClusterEdges();

        friend double interClusterEdges(const Cluster &c1, const Cluster &c2);

        void setPointDemensions(unsigned int);

        LNodePtr getheadpointer() { return points; }

        bool isCentroidValid() {return __centroidvalidity;}

        const PointPtr &operator[](unsigned int u) const;

        bool contains(const PointPtr &ptr) const;

    };



}
#endif //CLUSTERING_CLUSTER_H

