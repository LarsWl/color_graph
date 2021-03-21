// #include <Agorithm.h>

// class Compare
// {
//     public:
//     bool operator() (Graph G, Vertex a, Vertex b)
//     {
//         return G.get_degree(a)<G.get_degree(b);
//     }
// };


// class Algorithm
// {
// public:
//     void f ()
//     {

//     }
//     void search_color(vector <int> &a, int &b)
//     {
//         vector <int> color_V;
//         vector <int> child;
//         vector <int> color_child;
//         for (int i=0; i<a.size(); i++)
//         {
//             for (int j=0; j<p ; j++)
//             {
//                 child[j]=a[j];
//                 color_child.insert(color_V[j])
//             }
//             for (int j=p+1; j<a.size(); j++)
//             {
//                 child[j]=a[j];
//                 color_child.insert(color_V[j]);
//             }
//             child[p]=p;
//             color_child.insert(p);
//             if (color_child.size()<b && решение корректно)
//             {
//                     //запуск от этого вектора child[i];
//                     // реккурсия
//             }
//         }
//     }
//     void algorithm2 (Graph &G)
//     {
//         vector <int> color_V;
//         for (int i=0; i<myGraph.size(); i++)
//         {
//             color_V[i]=i+1;
//         }
//         b=myGraph.size();
//         vector <int> child;
//         vector <int> color_child;
//         for (int i=0; i<myGraph.size(); i++)
//         {
//             for (int j=0; j<p; j++)
//             {
//                 child[j]=color_V[j];
//                 color_child.insert(color_V[j])
//             }
//             for (int j=p+1; j<myGraph.size(); j++)
//             {
//                 child[j]=color_V[j];
//                 color_child.insert(color_V[j]);
//             }
//             child[p]=p;
//             color_child.insert(p);
//             if (color_child.size()<b && решение корректно)
//             {
//                     //запуск от этого вектора child[i];
//                     // реккурсия
//                    search_color(*child, *color_child.size())
//             }
//         }
//     }
// };
// корректность: две вершины одного цвета соединены или нет
