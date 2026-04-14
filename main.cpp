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








template< class T, class Cmp >
bool less(T t1, T t2, Cmp cmp)
{
  return cmp(t1, t2);
}

template< class T, class Cmp >
bool greater(T t1, T t2, Cmp cmp)
{
  return cmp(t2, t1);
}

template< class T, class Cmp >
bool notEqual(T t1, T t2, Cmp cmp)
{
  return less(t1, t2, cmp) || greater(t1, t2, cmp);
}


template< class T, class Cmp >
std::pair< bool, BiTreeIt< T > > isEqualRange(BiTree< T > * b1, BiTree< T > * e1, BiTree< T > * b2, Cmp cmp)
{
  while (b1 != e1 && hasNext(b2))
  {
    if (notEqual(b1->val, b2->val, cmp))
    {
      return false;
    }

    b1 = next(b1);
    b2 = next(b2);
  }
  return b1 == e1;
}

// !! Не доделана
template< class T, class Cmp >
bool isEqual(BiTree< T > * lhs, BiTree< T > * rhs, Cmp cmp)
{
  if (!lhs && ! rhs)
  {
    return true;
  }

  BiTree< T > * b1 = fallLeft(lhs);
  BiTree< T > * b2 = fallLeft(rhs);

  isEqualRange(b1, nullptr, b2, cmp);

  return !hasNext(b1) && !hasNext(b2);
}

template< class T, class Cmp >
BiTree< T > * finde(const BiTree< T > * r, T val, Cmp cmp);

template< class T, class Cmp >
bool included(BiTree< T > * origin, BiTree< T > * rhs, Cmp cmp)
{
  if (!rhs)
  {
    return true;
  }

  if (!origin)
  {
    return false;
  }

  BiTree< T > * brhs = fallLeft(rhs);
  BiTree< T > * bo = finde(origin, brhs->val, cmp);

  return isEqualRange(brhs, nullptr, bo, cmp).first;
}



int main()
{
  return 0;
}
