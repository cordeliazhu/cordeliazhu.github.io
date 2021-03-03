# ECE6254 Support Vector Machine
## Basic notion
w is the orthogonal to all vectors that are parallel to the hyperplane.

slack variable（$$ \zeta $$)被引入用于解决线性不可分的问题
这样子公式变为$$y_i(w^Tx_i + b) >= 1- \zeta_i$$. 对此我们引入cost parameter得到soft margin hyperplane. $$(w^*,b^*) = argmin_{w,b,\zeta}1/2||w|| +C/n \sum\ zeta$$ 。 为什么会变成这样子的公式呢， 因为目标是最大化别的项对


