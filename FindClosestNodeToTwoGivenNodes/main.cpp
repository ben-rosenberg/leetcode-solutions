#include <iostream>
#include <vector>

#define Edges std::vector<int>


/**
 * @brief Leetcode problem #2359: Find Closest Node to Given Two Nodes
 * 
 * "You are given a directed graph of n nodes numbered from 0 to n - 1, where
 * each node has at most one outgoing edge. The graph is represented with a
 * given 0-indexed array edges of size n, indicating that there is a directed
 * edge from node i to node edges[i]. If there is no outgoing edge from i,
 * then edges[i] == -1. You are also given two integers node1 and node2.
 * 
 * "Return the index of the node that can be reached from both node1 and node2,
 * such that the maximum between the distance from node1 to that node, and from
 * node2 to that node is minimized. If there are multiple answers, return the
 * node with the smallest index, and if no possible answer exists, return -1.
 * 
 * "Note that edges may contain cycles."
 */
class Solution
{
public:
    /**
     * @brief Finds the closest meeting node between two nodes
     * 
     * Calls the getDistanceFromNode() method for both nodes. The meeting node
     * with the shortest distance from each node--as defined in the problem
     * statement--is returned.
     * 
     * @param edges An edge exists from node i to node edges[i]. If edges[i] == -1,
     * node i has no outgoing edge
     * @param node1 
     * @param node2 
     * @return int The node reachable from both node1 and node2 with the shortest
     * distance from node1 and node2
     */
    int closestMeetingNode(std::vector<int> &edges, int node1, int node2)
    {
        std::vector<int> distances_from_node1 = getDistancesFromNode(edges, node1);
        std::vector<int> distances_from_node2 = getDistancesFromNode(edges, node2);

        int min_so_far = -1;
        int meeting_node = -1;

        for (int i = 0; i < edges.size(); i++) {
            if (distances_from_node1[i] == -1 || distances_from_node2[i] == -1)
                continue;
            
            int max_distance = distances_from_node1[i] > distances_from_node2[i] ? distances_from_node1[i] : distances_from_node2[i];

            if (min_so_far == -1 || max_distance < min_so_far) {
                min_so_far = max_distance;
                meeting_node = i;
            }
        }

        return meeting_node;
    }

    /**
     * @brief Get the distances from node to every other node.
     * 
     * @param edges 
     * @param node 
     * @return std::vector<int> 
     */
    std::vector<int> getDistancesFromNode(Edges &edges, int node) {
        std::vector<int> distances(edges.size(), -1);
        bool *visited = new bool[edges.size()]{false};
        int steps_counter = 0;

        for (int runner_node = node; runner_node != -1; runner_node = edges[runner_node]) {
            if (visited[runner_node]) break;

            visited[runner_node] = true;
            distances[runner_node] = steps_counter;
            steps_counter++;
        }

        return distances;
    }
};

int main()
{
    Solution s;
    Edges e1 = {2, 2, 3, -1};

    std::cout << s.closestMeetingNode(e1, 0, 1);

    std::cout << '\n';
}