#include <iostream>

template< class T >
struct BiTree
{
  T val;
  BiTree< T > * lt, * rt, * parent;
};

template< class T, class F >
BiTree< T > * fallLeft(BiTree< T > * node)
{
  if (!node)
  {
    return node;
  }

  while (node->lt)
  {
    node = node->lt;
  }

  return node;
}


template< class T, class F >
F travers(BiTree< T > * root, F f)
{
  if (!root)
  {
    return f;
  }

  BiTree< T > * curr = fallLeft(root);

  while (curr)
  {
    f(curr->val);

    if (curr->val)
    {
      curr = fallLeft(curr->rt);
    }
    else
    {
      BiTree< T > * parent = curr->parent;

      while (parent && parent->lt != curr)
      {
        curr = parent;
        parent = curr->parent;
      }

      curr = parent;
    }
  }
  
  return f;
}


template< class T >
struct BiTreeIt
{
  BiTree< T > * curr;
};



template< class T >
T & value(BiTreeIt< T > it)
{
  return it.curr->val;
}


template< class T >
BiTreeIt< T > next(BiTreeIt< T > it)
{
  BiTree< T > * curr = it.curr;

  if (!curr)
  {
    return it;
  }

  if (curr->rt)
  {
    curr = fallLeft(curr->rt);
  }
  else
  {
    BiTree< T > * parent = curr->parent;

    while (parent && parent->rt != curr)
    {
      curr = parent;
      parent = curr->parent;
    }

    curr = parent;
  }

  return {curr};
}


template< class T, class F >
BiTree< T > * fallRight(BiTree< T > * node)
{
  if (!node)
  {
    return node;
  }

  while (node->rt)
  {
    node = node->rt;
  }

  return node;
}

template< class T >
BiTreeIt< T > prev(BiTreeIt< T > it)
{
  BiTree< T > * curr = it.curr;

  if (!curr)
  {
    return it;
  }

  if (curr->lt)
  {
    curr = fallRight(curr->lt);
  }
  else
  {
    BiTree< T > * parent = curr->parent;

    while (parent && parent->lt != curr)
    {
      curr = parent;
      parent = curr->parent;
    }

    curr = parent;
  }

  return {curr};
}


template< class T >
bool hasNext(BiTreeIt< T > it)
{
  return next(it).curr;
}

template< class T >
bool hasPrev(BiTreeIt< T > it)
{
  return prev(it).curr;
}


template< class T, class Cmp>
bool isEqual(BiTreeIt< T > * lhs, BiTreeIt< T > * rhs, Cmp cmp)
{
  if (!lhs && ! rhs)
  {
    return true;
  }
  
  
}






int main()
{


  return 0;
}
