#ifndef PLANNER_H
#define PLANNER_H

#include <iostream>
#include <ctime>

#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_listener.h>
#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include "constants.h"
#include "helper.h"
#include "collisiondetection.h"
#include "algorithm.h"
#include "node3d.h"
#include "path.h"
#include "visualize.h"
#include "lookup.h"

namespace HybridAStar {
class Planner {
 public:
  /// default constructor
    Planner();

  /*!
     \brief Initializes the collision as well as heuristic lookup table
     \todo probably removed
  */
  void initializeLookups();

  /*!
   * \brief setMap
   * \param map the map provided as nav_msgs::OccupancyGrid
   */
  void setMap(const nav_msgs::OccupancyGrid::Ptr map);

  /*!
   * \brief setStart
   * \param initial the start pose
   */
  void setStart(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& start);

  /*!
   * \brief setGoal
   * \param end the goal pose
   */
  void setGoal(const geometry_msgs::PoseStamped::ConstPtr& goal);

  /*!
   * \brief The central function entry point making the necessary preparations to start the planning.
   */
  void plan();

 private:
  /// The node handle
  ros::NodeHandle n;
  /// A publisher publishing the start position for RViz
  ros::Publisher pubStart;
  /// A subscriber for receiving map updates
  ros::Subscriber subMap;
  /// A subscriber for receiving goal updates
  ros::Subscriber subGoal;
  /// A subscriber for receiving start updates
  ros::Subscriber subStart;
  /// A listener that awaits transforms
  tf::TransformListener listener;
  /// A transform for moving start positions
  tf::StampedTransform transform;
  /// The path used for tracing and visualization
  Path path;
  /// The visualization used for search visualization
  Visualize visualization;
  /// The collission detection for testing specific configurations
  CollisionDetection configurationSpace;
  /// A pointer to the grid the planner runs on
  nav_msgs::OccupancyGrid::Ptr grid;
  /// The start pose set through RViz
  geometry_msgs::PoseWithCovarianceStamped start;
  /// The goal pose set through RViz
  geometry_msgs::PoseStamped goal;
  /// Flags for allowing the planner to plan
  bool validStart = false;
  /// Flags for allowing the planner to plan
  bool validGoal = false;
  Constants::config collisionLookup[Constants::headings * Constants::positions];
  float* dubinsLookup = new float [Constants::headings * Constants::headings * Constants::dubinsWidth * Constants::dubinsWidth];
};
}
#endif // PLANNER_H