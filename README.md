
# PBench: A Parallel, Real-Time Benchmark Suite

PBench is a parallel, real-time benchmark suite esapecially developed to help WCET analysis studies. It is a collection of parallel programs which can be used to compare real-time platforms and WCET analysis tools. All programs in the benchmark suite are open source and licensed under the MIT license.


## Citing PBench

The paper of PBench can be accessed through the link below.

https://www.acperpro.com/document/ISITES2018ID37

If you use PBench in your research, please consider citing.

S. Serttaş and V. H. Şahin, “PBench: A Parallel, Real-Time Benchmark Suite,” in Academic Perspective Procedia, Alanya, Antalya, Turkey, Nov. 2018, vol. 1, pp. 178–186, doi: 10.33793/acperpro.01.01.37

```bibtex
@inproceedings{PBench_2018,
	address = {Alanya, Antalya, Turkey},
	title = {{PBench}: {A} {Parallel}, {Real}-{Time} {Benchmark} {Suite}},
	volume = {1},
	url = {http://www.acperpro.com/document/ISITES2018ID37},
	doi = {10.33793/acperpro.01.01.37},
	booktitle = {Academic {Perspective} {Procedia}},
	author = {Serttaş, Sevil and Şahin, Veysel Harun},
	month = nov,
	year = {2018},
	pages = {178--186},
}
```

## Feature Matrix

Below is the feature matrix of PBench.

### Abbreviations

Single Threaded (ST)  
Multi Threaded (MT)  
External Routine (ER)    
Single Path (SP)  
Multi Path (MP)  
Dynamic Memory (DM)  
Loop (L)  
Nested Loop (NL)  
Recursion (R)  
Decision (D)  
Array (A)  
Bit Level Operation (BLO)  
Floating Point Operation (FPO)  
Integer Operation (IO)  
Input Vector (IVEC)  
Input Value (IVAL)  
Input File (IF)  

### Feature Matrix

Program Name | ST | MT | ER | SP | MP | DM| L | NL | R | D | A | BLO | FPO | IO | IVEC | IVAL | IF |
:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
p_matrix_multiplication | - | + | + | - | + | - | + | + | - | - | + | - | - | + | - | - | - | 
matrix_multiplication   | + | - | + | - | + | - | + | + | - | - | + | - | - | + | - | - | - | 
p_selection_sort        | - | + | + | - | + | - | + | - | - | + | + | - | - | + | - | - | - | 
selection_sort          | + | - | + | - | + | - | + | - | - | + | + | - | - | + | - | - | - |  
p_array_search          | - | + | + | + | - | - | + | - | - | + | + | - | - | + | - | - | - | 
array_search            | + | - | + | + | - | - | + | - | - | + | + | - | - | + | - | - | - | 
p_factorial             | - | + | + | - | + | - | + | - | - | + | + | - | - | + | - | + | - | 
factorial               | + | - | + | - | + | - | - | - | + | + | - | - | - | + | - | + | - | 
p_binomial_distribution | - | + | + | + | - | - | + | - | - | - | + | - | - | + | - | - | - | 
binomial_distribution   | + | - | + | + | - | - | + | - | - | - | - | - | - | + | - | - | - | 
p_prime_numbers         | - | + | + | + | - | - | + | + | - | + | + | - | - | + | - | - | - | 
prime_numbers           | + | - | + | + | - | - | + | - | - | + | - | - | - | + | - | - | - | 
p_linear_regression     |-  | + | + | + | - | - | + | - | - | - | + | - | + | - | - | - | - | 
linear_regression       | + | - | + | + | - | - | + | - | - | - | + | - | + | - | - | - | - |
