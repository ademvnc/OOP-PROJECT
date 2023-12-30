// 152120211109
// Path.h

#ifndef PATH_H
#define PATH_H

#include "Pose.h"

/**
 * @brief The Path class represents a path consisting of poses.
 */
class Path {
private:
    struct Node {
        Pose data; ///< Pose data stored in the node.
        Node* next; ///< Pointer to the next node.

        /**
         * @brief Constructor for the Node struct.
         * @param pose The pose to be stored in the node.
         */
        Node(const Pose& pose) : data(pose), next(nullptr) {}
    };

    Node* head; ///< Pointer to the first node (head) in the path.
    Node* tail; ///< Pointer to the last node (tail) in the path.
    int number; ///< Number of elements in the path.

public:
    /**
     * @brief Constructor for the Path class.
     */
    Path();

    /**
     * @brief Destructor for the Path class.
     */
    ~Path();

    /**
     * @brief Add a pose to the path.
     * @param pos The pose to be added to the path.
     */
    void addPos(const Pose& pos);

    /**
     * @brief Print the poses in the path to the console.
     */
    void print() const;

    /**
     * @brief Overload the indexing operator to access a pose at a specific index.
     * @param index The index of the pose to be accessed.
     * @return The pose at the specified index.
     */
    Pose operator[](int index) const;

    /**
     * @brief Get the pose at a specific index in the path.
     * @param index The index of the pose to be retrieved.
     * @return The pose at the specified index.
     */
    Pose getPos(int index) const;

    /**
     * @brief Remove the pose at a specific index from the path.
     * @param index The index of the pose to be removed.
     */
    void removePos(int index);

    /**
     * @brief Insert a pose at a specific index in the path.
     * @param index The index at which the pose will be inserted.
     * @param pos The pose to be inserted.
     */
    void insertPos(int index, const Pose& pos);
};

#endif // PATH_H
