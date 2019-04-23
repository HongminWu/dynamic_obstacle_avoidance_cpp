#include "DynamicObstacleAvoidance/modulation.hpp"

namespace Modulation
{
	Eigen::VectorXf compute_normal_to_obstacle(const Obstacle& obstacle, const Eigen::VectorXf& agent_position)
	{
		// the normal to the obstacle is the opposite of the normal to the agent in the obstacle reference frame
		return (-1) * obstacle.compute_normal_to_external_point(agent_position);
	}

	Eigen::VectorXf compute_direction_to_obstacle(const Obstacle& obstacle, const Eigen::VectorXf& agent_position)
	{
		return obstacle.get_reference_position() - agent_position;
	}

	double compute_distance_to_obstacle(const Obstacle& obstacle, const Eigen::VectorXf& agent_position)
	{
		return obstacle.compute_distance_to_external_point(agent_position);
	}

	double compute_modulation_matrix(const Agent& agent, const Obstacle& obstacle, Eigen::MatrixXf& basis, Eigen::MatrixXf& orthogonal_basis, Eigen::MatrixXf& eigenvalues)
	{
		Eigen::VectorXf agent_position = agent.get_position();
		// compute all necessary vectors
		Eigen::VectorXf normal_to_obstacle = compute_normal_to_obstacle(obstacle, agent_position);
		Eigen::VectorXf direction_to_obstacle = compute_direction_to_obstacle(obstacle, agent_position);
		double distance_to_obstacle = compute_distance_to_obstacle(obstacle, agent_position);

		return distance_to_obstacle;
	}

	Eigen::VectorXf modulate_velocity(const Agent& agent, const std::list<Obstacle>& obstacles, const std::list<Eigen::VectorXf>& attractor_positions)
	{
		if(obstacles.empty()) return agent.get_velocity();
		int dim = agent.get_position().size();

		// initialize the list of matrices for calculation
		std::list<Eigen::MatrixXf> basis_list;
		std::list<Eigen::MatrixXf> orthogonal_basis_list;
		std::list<Eigen::MatrixXf> eigenvalues_list;
		std::list<double> distances_list;

		for(const Obstacle& obs:obstacles)
		{
			Eigen::MatrixXf basis(dim, dim);
			Eigen::MatrixXf orthogonal_basis(dim, dim);
			Eigen::MatrixXf eigenvalues(dim, dim);

			double distance = compute_modulation_matrix(agent, obs, basis, orthogonal_basis, eigenvalues);
			basis_list.push_back(basis);
			orthogonal_basis_list.push_back(orthogonal_basis);
			eigenvalues_list.push_back(eigenvalues);
			distances_list.push_back(distance);
		}
	}
}