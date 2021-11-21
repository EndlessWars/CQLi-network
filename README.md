# Dynamic Analysis of Digital Chaotic Maps via State-Mapping Networks

The paper titled "Dynamic Analysis of Digital Chaotic Maps via State-Mapping Networks" is available on IEEE: https://ieeexplore.ieee.org/document/8602460. 
This project contains codes of this paper, LaTeX source codes of this paper can be downloaded:  https://arxiv.org/format/1410.7694. 

Cite this paper:

IEEE format: 

C. Li, B. Feng, S. Li, J. Kurths and G. Chen, "Dynamic Analysis of Digital Chaotic Maps via State-Mapping Networks," 
in IEEE Transactions on Circuits and Systems I: Regular Papers, vol. 66, no. 6, pp. 2322-2335, June 2019, doi: 10.1109/TCSI.2018.2888688.

```bib

@article{cqli:network:TCASI2019,
  author =       {Chengqing Li and Bingbing Feng and Shujun Li and Ju\"ergen Kurths and Guanrong Chen},
  title =        {Dynamic analysis of digital chaotic maps via state-mapping networks},
  journal =      {IEEE Transactions on Circuits and Systems I: Regular Papers},
  year =         {2019},
  volume =       {66},
  number =       {6},
  pages =        {2322--2335},
  doi =          {10.1109/TCSI.2018.2888688},
}
```



## Code introduction

This is the supporting code for the paper. The C++ code is mainly used for data operation, and the matlab code is mainly used for drawing and data processing. You can easily compile and run them.
The code is given in three parts: Fixed-Point, Floating-Point, and SMN-Analysis, corresponding to sections 2, 3, and 4 in the paper.

## Fixed-Point

The code of section II.
- Logistic map

This part contains the calculation process and related image drawing process of Logistic Map in fixed-point arithmetic domain.

`test_fixed_point` gives the actual performance of Property 4 of Logistic Map in the real fixed-point arithmetic domain.`bit_precision_logistic_even.cpp` is used to generate results for even-numbered nodes in fixed-point arithmetic domain.`bit_precision_logistic_odd.cpp` is used to generate results for odd-numbered nodes in fixed-point arithmetic domain.`bit_precision_logistic.cpp` is used to generate results for all nodes in fixed-point arithmetic domain. You can set the specified positive integer value in the code to control the accuracy of the fixed-point arithmetic domain. Then use the matlab code `upper_bound_add.m` to verify Property 4.

`theorem_1` gives the calculation method of SMN in-degree of Logistic Map under the given accuracy, and gives the drawing code of Fig. 3. `node_indegree.cpp` gives the number of nodes corresponding to different indegree values.You can enter the specified positive integer value in the program to control the accuracy of the fixed-point arithmetic domain. The code `theorem1.m` converts these data into images.

`ind_num` gives the in-degree distribution and cumulative in-degree distribution of Logistic Map.The output result of `cumulative_indegree_distribution.cpp` is the cumulative indegree distribution of the Logistic Map in the specified fixed-point arithmetic domain. You can enter the specified positive integer value in the program to control the accuracy of the fixed-point arithmetic domain. `cumulative_indegree_distribution.m` converts these data into more intuitive images.The code `indegree_distribution.cpp` and `indegree_distribution.m` show the indegree distribution of Logistic Map.

- Tent map

This part contains the calculation process and related image drawing process of Tent Map in fixed-point arithmetic domain.

`tent_fixed_point` gives the actual performance of Property 4 of Tent Map in the real fixed-point arithmetic domain.`bit_precision_Tent_even.cpp` is used to generate results for even-numbered nodes in fixed-point arithmetic domain.`bit_precision_Tent_odd.cpp` is used to generate results for odd-numbered nodes in fixed-point arithmetic domain.`bit_precision_Tent.cpp` is used to generate results for all nodes in fixed-point arithmetic domain. You can set the specified positive integer value in the code to control the accuracy of the fixed-point arithmetic domain. Then use the matlab code `upper_bound_add.m` to verify Property 4.

`tent_indegree` gives the in-degree distribution and cumulative in-degree distribution of Tent Map.The output result of `cumulative_indegree_distribution.cpp` is the cumulative indegree distribution of the Tent Map in the specified fixed-point arithmetic domain. You can enter the specified positive integer value in the program to control the accuracy of the fixed-point arithmetic domain. And The code `indegree_distribution.cpp` show the indegree distribution of Tent Map.

## Floating-Point

The code of section III.
- Binary16_Diffierences

This part gives the calculation process and results of using 16bit precision to calculate the intermediate value of Logistic Map.`v_bit.hpp` is a header file that can specify the order code and the length of the mantissa, you can adjust the relevant parameters in this file. In the code `bit_precision_logistic.cpp`, the intermediate value of the Logistic Map under binary16 floating-point precision is calculated. The code `floating_point_format_0_1.cpp` uses 16bit floating point numbers to calculate the Logistic Map and converts the result to the specified low-precision floating point number. The code `test.cpp` directly uses the specified low-precision floating point number to calculate the Logistic Map and compares it with the output result of `floating_point_format_0_1.cpp`.

- Logistic map

This part gives the in-degree distribution of Logistic Map in the floating-point arithmetic domain.The output result of `indegree_distribution.cpp` is the indegree distribution of the Logistic Map in the specified floating-point arithmetic domain and `cumulative_indegree_distribution.m` converts these data into more intuitive images.

- Tent map

The code `tent_binary.cpp` uses a random algorithm to verify the mathematical expectation of Nr. You can change the variable type of x in the code to control the floating-point precision to determine the range of Nr. Then use the maylab code `DL_binary.m` to plot these data onto the image.


## SMN-Analysis

The code of section IV.

- Parameter_Perturbation

This part gives the code to visualize SMN through perturb the control parameters. The code `bit_precision_logistic_u_perturbation.cpp` shows a method of changing the SMN path through disturbance control parameters. `u_perturbation_filter.cpp` and `u_perturbation_sort.cpp` format these data.

- DWSCS_All

This part gives the code to visualize SMN through switch among multiple chaotic maps. The code `DWSCS_ALL.cpp` cascades the two chaotic maps of Logistics Map and Tent Map to verify the conclusion of Section 4.
