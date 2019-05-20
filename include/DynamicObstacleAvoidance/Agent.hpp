/**
 * @class Modulation
 * @brief Class to define Modulations of the dynamical system
 * @author Baptiste Busch
 * @date 2019/04/16
 */

#ifndef DYNAMIC_OBSTACLE_AVOIDANCE_AGENT_H_
#define DYNAMIC_OBSTACLE_AVOIDANCE_AGENT_H_

#include <eigen3/Eigen/Core>
#include "DynamicObstacleAvoidance/State/State.hpp"
#include "DynamicObstacleAvoidance/State/Pose.hpp"

class Agent
{
private:
	State state;
	double safety_margin;

public:
	explicit Agent(const State& state, const double& safety_margin=0.0);

	inline const State get_state() const 
	{ 
		return this->state;
	}

	inline const Pose get_pose() const 
	{ 
		return this->state.get_pose();
	}

	inline const Eigen::Vector3d get_position() const 
	{ 
		return this->state.get_position();
	}

	inline const Eigen::Quaterniond get_orientation() const 
	{ 
		return this->state.get_orientation();
	}

	inline const Eigen::Vector3d get_linear_velocity() const
	{
		return this->state.get_linear_velocity();
	}

	inline const Eigen::Vector3d get_angular_velocity() const
	{
		return this->state.get_angular_velocity();
	}

	inline double get_safety_margin() const
	{ 
		return this->safety_margin;
	}

	inline void set_safety_margin(const double& safety_margin)
	{ 
		this->safety_margin = safety_margin;
	}

	inline void set_pose(const Pose& pose)
	{
		this->state.set_pose(pose);
	}

	inline void set_position(const Eigen::Vector3d& position)
	{
		this->state.set_position(position);
	}

	inline void set_orientation(const Eigen::Quaterniond& orientation)
	{
		this->state.set_orientation(orientation);
	}

	inline void set_linear_velocity(const Eigen::Vector3d& linear_velocity)
	{
		this->state.set_linear_velocity(linear_velocity);
	}

	inline void set_angular_velocity(const Eigen::Vector3d& angular_velocity)
	{
		this->state.set_angular_velocity(angular_velocity);
	}
};

#endif