// Pose.h

#ifndef POSE_H
#define POSE_H

/**
 * @brief The Pose class represents a pose in 2D space with x, y, and orientation (theta).
 */
class Pose {
public:
    /**
     * @brief Default constructor for the Pose class.
     */
    Pose();

    /**
     * @brief Parameterized constructor for the Pose class.
     * @param x The x-coordinate of the pose.
     * @param y The y-coordinate of the pose.
     * @param th The orientation (theta) of the pose.
     */
    Pose(double x, double y, double th);

    /**
     * @brief Get the x-coordinate of the pose.
     * @return The x-coordinate.
     */
    double getX() const;

    /**
     * @brief Get the y-coordinate of the pose.
     * @return The y-coordinate.
     */
    double getY() const;

    /**
     * @brief Get the orientation (theta) of the pose.
     * @return The orientation.
     */
    double getTh() const;

    /**
     * @brief Set the x-coordinate of the pose.
     * @param x The new x-coordinate.
     */
    void setX(double x);

    /**
     * @brief Set the y-coordinate of the pose.
     * @param y The new y-coordinate.
     */
    void setY(double y);

    /**
     * @brief Set the orientation (theta) of the pose.
     * @param th The new orientation.
     */
    void setTh(double th);

    /**
     * @brief Compare two poses for equality.
     * @param other The other pose to compare with.
     * @return True if the poses are equal, false otherwise.
     */
    bool operator==(const Pose& other) const;

    /**
     * @brief Add two poses element-wise.
     * @param other The other pose to add.
     * @return The result of the addition.
     */
    Pose operator+(const Pose& other) const;

    /**
     * @brief Subtract two poses element-wise.
     * @param other The other pose to subtract.
     * @return The result of the subtraction.
     */
    Pose operator-(const Pose& other) const;

    /**
     * @brief Add another pose to this pose.
     * @param other The other pose to add.
     * @return A reference to the modified pose.
     */
    Pose& operator+=(const Pose& other);

    /**
     * @brief Subtract another pose from this pose.
     * @param other The other pose to subtract.
     * @return A reference to the modified pose.
     */
    Pose& operator-=(const Pose& other);

    /**
     * @brief Compare two poses based on their lexicographical order (x, y, th).
     * @param other The other pose to compare with.
     * @return True if this pose is less than the other, false otherwise.
     */
    bool operator<(const Pose& other) const;

    /**
     * @brief Get the pose values (x, y, th) as references.
     * @param x Reference to store the x-coordinate.
     * @param y Reference to store the y-coordinate.
     * @param th Reference to store the orientation (theta).
     */
    void getPose(double& x, double& y, double& th) const;

    /**
     * @brief Set the pose values (x, y, th) using provided values.
     * @param x The new x-coordinate.
     * @param y The new y-coordinate.
     * @param th The new orientation (theta).
     */
    void setPose(double x, double y, double th);

    /**
     * @brief Calculate the Euclidean distance to another pose.
     * @param pos The other pose.
     * @return The Euclidean distance between this pose and the other pose.
     */
    double findDistanceTo(const Pose& pos) const;

    /**
     * @brief Calculate the angle to another pose.
     * @param pos The other pose.
     * @return The angle (in radians) between this pose and the other pose.
     */
    double findAngleTo(const Pose& pos) const;

private:
    double x_; ///< The x-coordinate of the pose.
    double y_; ///< The y-coordinate of the pose.
    double th_; ///< The orientation (theta) of the pose.
};

#endif // POSE_H
