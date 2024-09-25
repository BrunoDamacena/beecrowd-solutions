#include <iostream>
#include <vector>
#include <cmath>

struct Sensor {
    int x;
    int y;
    int s;
    int cluster = -1; // ill try to group sensors that intersects with each other into clusters of sensors
};

bool sensorsIntersect(Sensor s1, Sensor s2) {
    int distanceSquared = std::pow(s1.x - s2.x, 2) + std::pow(s1.y - s2.y, 2);
    int radiusSquared = std::pow(s1.s + s2.s, 2);
    // if the distance is less or equal to the sum of the radius, the sensors intersect
    return distanceSquared <= radiusSquared;
}

bool sensorBlocksPainting(int minX, int maxX, int minY, int maxY, int m, int n) {
    bool blocksXWall = minX <= 0 && maxX >= n;
    bool blocksYWall = minY <= 0 && maxY >= m;
    bool blocksStartDiag = minX <= 0 && minY <= 0;
    bool blocksEndingDiag = maxX >= n && maxY >= m;
    
    // blocks if the cluster forms a wall on X or Y or a diagonal blocking the starting or the ending position
    return blocksXWall || blocksYWall || blocksStartDiag || blocksEndingDiag;
}

char canStealThePainting(int m, int n, int k, std::vector<Sensor> sensors) {
    std::vector<std::vector<Sensor>> sensorCluster;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j) {
                continue;
            }
            // if they intersect, find the cluster that they belong and group them
            if (sensorsIntersect(sensors[i], sensors[j])) {
                // if some of them are not in a cluster yet
                if (sensors[i].cluster != -1 || sensors[j].cluster != -1) {
                    // they are already grouped
                    if (sensors[i].cluster == sensors[j].cluster) {
                        continue;
                    }
                    // if some of them is not in a cluster yet, add one into anothers cluster
                    if (sensors[i].cluster == -1 || sensors[j].cluster == -1) {
                        int cluster;
                        if (sensors[i].cluster == -1) {
                            cluster = sensors[j].cluster;
                            sensorCluster[cluster].push_back(sensors[i]);
                            sensors[i].cluster = cluster;
                        } else {
                            cluster = sensors[i].cluster;
                            sensorCluster[cluster].push_back(sensors[j]);
                            sensors[j].cluster = cluster;
                        }
                    } else { // both of them are in a cluster yet: group them into one
                        int clusterI = sensors[i].cluster;
                        int clusterJ = sensors[j].cluster;
                        for (int k = 0; k < sensorCluster[clusterJ].size(); k++) {
                            sensorCluster[clusterI].push_back(sensorCluster[clusterJ][k]);
                            sensorCluster[clusterJ][k].cluster = clusterI;
                        }
                        sensorCluster[clusterJ] = std::vector<Sensor>();
                    }
                } else { // if neither are in a cluster, add them into one together
                    int cluster = sensorCluster.size();
                    sensors[i].cluster = cluster;
                    sensors[j].cluster = cluster;
                    sensorCluster.push_back(std::vector<Sensor>({sensors[i],sensors[j]}));
                }
            }
        }
        // add this sensor alone into a cluster if has not been added on this iteration
        if (sensors[i].cluster == -1) {
            sensorCluster.push_back(std::vector<Sensor>({sensors[i]}));
        }
    }

    // now, lets check if any of the cluster blocks the access to the painting
    for (int i = 0; i < sensorCluster.size(); i++) {
        int minX = n+1;
        int maxX = 0;
        int minY = m+1;
        int maxY = 0;
        // for all of the sensors in the cluster, lets find the min and max X and Y values that they block
        for (int j = 0; j < sensorCluster[i].size(); j++){
            Sensor s = sensorCluster[i][j];
            minX = std::min(minX, s.x - s.s);
            maxX = std::max(maxX, s.x + s.s);
            minY = std::min(minY, s.y - s.s);
            maxY = std::max(maxY, s.y + s.s);
        }
        if (sensorBlocksPainting(minX, maxX, minY, maxY, m, n)){
            // std::cout << "BLOCKS! minX = " << minX << ", maxX = " << maxX << "; minY = " << minY << ", maxY = " << maxY << "; m = " << m << ", n = " << n << std::endl;
            return 'N';
        }
        // else {
            // std::cout << "DOESNT BLOCKS! minX = " << minX << ", maxX = " << maxX << "; minY = " << minY << ", maxY = " << maxY << "; m = " << m << ", n = " << n << std::endl;
        // }
    }
    return 'S';
}

int main() {
    int m, n, k;

    std::cin >> n >> m >> k;
    std::vector<Sensor> sensors(k);
    for (int i = 0; i < k; i++) {
        int x, y, s;
        std::cin >> x >> y >> s;
        sensors[i] = {x, y, s};
    }

    std::cout << canStealThePainting(m, n, k, sensors) << std::endl;

    return 0;
}