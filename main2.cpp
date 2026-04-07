#include <iostream>

template< class T >
struct TriTree
{
  T val0, val1;
  TriTree< T > * lt, * rt, * mid, * parent;
};

!!!!!!!!!!!!!!!!
template< class T, class F >
TriTree< T > * fallLeft(TriTree< T > * node)
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

!!!!!!!!!!!!!!
template< class T, class F >
F travers(TriTree< T > * root, F f)
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
struct TriTreeIt
{
  size_t s;
  TriTree< T > * curr;
};



template< class T >
T & value(TriTreeIt< T > it)
{
  if (!it.s)
  {
    return it.curr->val0;
  }
  return it.curr->val1;
}


template< class T >
TriTree< T > next(TriTree< T > it)
{
  TriTree< T > * curr = it.curr;
  size_t ind = it.s;

  if (!curr)
  {
    return it;
  }

  if (!ind)
  {
    if (curr->mid)
    {
      curr = curr->mid;
      curr = fallLeft(curr);
      ind = 0;
    }
    else
    {
      ind = 1;
    }
  }
  else
  {
    if (curr.rt)
    {
      curr = curr->rt;
      curr = fallLeft(curr);
      ind = 0;
    }
    else
    {
      TriTree< T > * parent = curr.parent;

      if (parent->mid == curr)
      {
        ind = 1;
        break;
      }
      if (parent->lt == curr)
      {
        ind = 0;
        break;
      }
      curr = parent;
      parent = curr->parent;
    }

    curr = parent;
  }

  return {ind, curr};
}

!!!!!!!!!!1
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

!!!!!!!!!!
template< class T >
TriTreeIt< T > prev(TriTreeIt< T > it)
{
  TriTree< T > * curr = it.curr;

  if (!curr)
  {
    return it;
  }

  if (!ind)
  {
    if (curr->mid)
    {
      curr = curr->mid;
      curr = fallLeft(curr);
      ind = 0;
    }
    else
    {
      ind = 1;
    }
  }
  else
  {
    if (curr.rt)
    {
      curr = curr->rt;
      curr = fallLeft(curr);
      ind = 0;
    }
    else
    {
      TriTree< T > * parent = curr.parent;

      if (parent->mid == curr)
      {
        ind = 1;
        break;
      }
      if (parent->lt == curr)
      {
        ind = 0;
        break;
      }
      curr = parent;
      parent = curr->parent;
    }

    curr = parent;
  }

  return {ind, curr};
}


template< class T >
bool hasNext(TriTreeIt< T > it)
{
  return next(it).curr;
}

template< class T >
bool hasPrev(TriTreeIt< T > it)
{
  return prev(it).curr;
}




int main()
{


  return 0;
}
