# ECE6254 Support Vector Machine
## Basic notion
w is the orthogonal to all vectors that are parallel to the hyperplane.

slack variable（$$ \zeta $$)被引入用于解决线性不可分的问题
这样子公式变为$$y_i(w^Tx_i + b) >= 1- \zeta_i$$. 对此我们引入cost parameter得到soft margin hyperplane. $$(w^*,b^*) = argmin_{w,b,\zeta}1/2||w|| +C/n \sum\ zeta$$ 。 为什么会变成这样子的公式呢， 因为目标是最大化别的项对

##SVM的损失函数是hinge loss
L(y,f(x)) = max(0, 1 -yf(x))

##我文章用的是交叉熵损失函数
本质上也是一种对数似然函数
$$loss = -1/n \sum_i y_ilna_i$$

sigmoid用于二分类，softmax用于多分类使用sigmoid作为激活函数的时候，常用交叉熵损失函数而不用均方误差损失函数，因为它可以完美解决平方损失函数权重更新过慢的问题，具有“误差大的时候，权重更新快；误差小的时候，权重更新慢”

