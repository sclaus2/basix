
#include "lattice.h"
#include "tabulate.h"
#include <Eigen/Dense>
#include <iomanip>
#include <iostream>

int main()
{
  int n = 3;

  // Reference triangle
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> v(3, 2);
  v << -1.0, -1.0, -1.0, 1.0, 1.0, -1.0;

  // Evaluate polynomial at nodes, and get inverse
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> pt = create_lattice(n, v);
  Eigen::MatrixXd r = tabulate_triangle(n, pt).transpose();
  Eigen::MatrixXd w = r.inverse();

  // Create a set of points for testing and evaluate at those points
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> pt2 = create_lattice(50, v);
  auto vals = tabulate_triangle(n, pt2);

  for (int i = 0; i < pt2.rows(); ++i)
    {
      Eigen::Matrix<double, Eigen::Dynamic, 1>  r = vals.row(i).transpose();
      auto t2 = (w * r).transpose();
         std::cout << std::setprecision(5) << std::fixed << std::setw(10) << pt2.row(i) << " " << t2 << "\n";
    }

  
  return 0;
}
