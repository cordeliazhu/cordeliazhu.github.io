#阿里巴巴暑期面试
##自我介绍
##简单介绍一些BERT
1.（提问）：知道一些基本的词向量编码方法吗？
（答）：两种分别是基于频率基于预测。(1.基于频率：tf-idf (2.
基于预测的词嵌入，CRow& Skip_gram和GloVe; （2.1skip-gram,实际使用中由于vocab-size很大所以采用负采样的方式来近似模拟多分类任务，在词表中随机选取几个代表词，通过最小化这几个代表词的概率去近似最小化的整体的预测概率。 对于目标词证样本最大化预测概率，模型三个tensor，代表中心词的tensor，代表目标词的tensor，代表目标词标签的tensor
（2.2 GloVe 根据语料库构建一个公现矩阵，距离越远的两个单词所占总计数的权重越小；再构建词向量和公现矩阵之间的关系
##LSTM缓解梯度消失爆炸的问题
 StSt 表示输入序列在时刻 tt的值。根据求导的链式法则，这种形式直接导致梯度被表示为连成积的形式，以致于造成梯度消失——粗略的说, 很多个小于1的项连乘就很快的逼近零。
##LSTM避免RNN的梯度爆炸
设定阈值和使用正则化减少权重 
爆炸梯度问题相对容易。
通过简单地收缩其规范超过的梯度来处理阈值，一种被称为梯度裁剪的技术。如果一个巨大的因素减少了梯度，就会受到影响。过于频繁的裁剪是非常有效的
##欧氏距离的详细定义和cosine距离的定义
欧式距离也称欧几里得距离，是最常见的距离度量，衡量的是多维空间中两个点之间的绝对距离。
$$dist(X,Y) = \sqrt{\sum(x_i -y_i)^2}$$
cosine similarity
$$cos(\theta) = \sum(x_i*y_i)/(\sqrt{(x_i)^2}*\sqrt{(y_i)^2})$$


BERT自监督模型
1.  RNN，没办法做并行，每个下一步都要前面的中间结果； 传统word2vec, 无法解决一词多义的问题，与训练好的向量就永久不变了； Encoder端可以并行计算，一次性将输入序列全部encoding出来，但Decoder端不是一次性把所有单词(token)预测出来的。对于每个序列，selfattention可以计算出，x_i，x_j的点乘结果。
2. self.attention 机制来进行并行计算，在输入输出都相同； self.attention来决定哪个重要， 考虑当前词的上下文语境
3.  BERT $$Z = softmax(Q*K^T/sqrt(d_k))*V$$ 第N个词在这个序列中于每一个的关系，每一次的输入序列不一样，不同上下文；矩阵惩罚的计算；并行加速
4.  Multi-head机制 Q，K，V 多头，得到多个特征表达，将所有特征拼接在一起，可以通过一层全连接来降维；输入输出都是向量，那么可以多层
5.  位置信息表达，加了positional encoding(余弦正弦周期表达;归一化： BN：让均值为0，标准差为1；LN：训练速度快更稳定。  连接：基本的残差链接，
加一个映射，至少不会比原来差
6.  decoder中有encoder-decoder attention(编码器KV）和self-attention； 加入mask机制，一个接着一个往后出答案，把需要预测的值遮挡到；得到最终输出结果，损失函数cross-
7.  BERT是transformer的encoder部分，得到的是向量的表示形式，不需要标签有预料就可以了
8.  【SEP】两个橘子之间的连接符，【CLS】表示要做分类的向量
9.  使用BERT  i.e.阅读理解题，输入文章和问题输出为理解答案的位置； 需要分别计算答案的启示和终止位置，单独对end索引做训练，end的特征向量对文章中的每个词做dot product(内积）softmax得到概率最大的为end=====训练出编码器
10. q，k，v分别是query，key，value，对于encoder self-attention，第一次计算的初始值是每个字的embedding，q用来和k做点乘计算相似度，这些相似度经过softmax变成权重，然后权重和v相乘，其实就是v的一个加权平均。如果是encoder-decoder attention，q是decoder的hidden state，k和v是encoder各个位置的hidden state。