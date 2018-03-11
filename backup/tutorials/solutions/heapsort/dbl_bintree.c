#include "dbl_bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <unistd.h>
#include <assert.h>

// allocate memory for the current node and descend left and right into its children
// note that we pass the address of the pointer to the left and right children
// it will thus be set at the next recursion level in the malloc,
// constructing the parent-child relationship automatically
void
dbl_bt_descend( dbl_bt_node_t **node, dbl_bt_node_t *parent, const unsigned int depth ){
  dbl_bt_node_t* newnode = malloc( sizeof(dbl_bt_node_t) );
  assert( (void*)newnode != NULL );
  
  newnode->parent = parent;
  newnode->data = (double*)NULL;
  newnode->l = (dbl_bt_node_t*)NULL;
  newnode->r = (dbl_bt_node_t*)NULL;
  (*node) = newnode;
  
  if( depth > 0 ){
    dbl_bt_descend( &((*node)->l), *node, depth-1 );
    dbl_bt_descend( &((*node)->r), *node, depth-1 );
  }
}

// find bottom-right-most node in the complete tree
dbl_bt_node_t*
dbl_bt_complete_get_bottomright( dbl_bt_complete_t* bt ){
  dbl_bt_node_t* curr_node = bt->root;
  while( curr_node->r != NULL ){
    curr_node = curr_node->r;
#ifdef BT_DEBUG
    printf("get_bottomright: %p with parent %p\n", (void*)curr_node, (void*)curr_node->parent);
#endif
  }
  return curr_node;
}

// find bottom-left-most node in the complete tree
dbl_bt_node_t*
dbl_bt_complete_get_bottomleft( dbl_bt_complete_t* bt ){
  dbl_bt_node_t* curr_node = bt->root;
  while( curr_node->l != NULL ){
    curr_node = curr_node->l;
#ifdef BT_DEBUG
    printf("get_bottomleft: %p with parent %p\n", (void*)curr_node, (void*)curr_node->parent);
#endif
  }
  return curr_node;
}

dbl_bt_node_t*
find_tail_node_dbl_bt( dbl_bt_node_t* node ){
  if( node->l != NULL && node->l->data != NULL ){
    return find_tail_node_dbl_bt( node->l );
  } else if ( node->r != NULL && node->r->data != NULL ){
    return find_tail_node_dbl_bt( node->r );
  }
  return node;
}

// initialise *empty* complete binary tree of a given depth recursively
dbl_bt_complete_t*
init_dbl_bt_complete( const unsigned int depth ){
  dbl_bt_complete_t* bt = malloc( sizeof(dbl_bt_complete_t) );
  
  bt->root = malloc( sizeof(dbl_bt_node_t) );
  bt->root->parent = (dbl_bt_node_t*) NULL;
  bt->root->data = (double*) NULL;
  bt->depth = depth;

  // top-down recursive tree structure setup for complete binary tree with empty data
  dbl_bt_descend( &(bt->root->l), bt->root, depth-1 );
  dbl_bt_descend( &(bt->root->r), bt->root, depth-1 );

  bt->bottomleft = dbl_bt_complete_get_bottomleft( bt );
  bt->bottomright = dbl_bt_complete_get_bottomright( bt );

  return bt;
}

// recursively free left and right children of a given node
// when the maximal recursion depth is reached, the children of the
// node will be NULL
void
free_dbl_bt_sub( dbl_bt_node_t *node ){
  if( node->l != NULL ){
    free_dbl_bt_sub( node->l );
  }
  if( node->r != NULL ){
    free_dbl_bt_sub( node->r );
  }
  free( node );
}

// free complete tree starting at root node
void
free_dbl_bt_complete(dbl_bt_complete_t *bt){
  free_dbl_bt_sub( bt->root );
  free(bt);
}

/* recursively fill the binary tree with data
 * if 'fill_last==0', the last row of the tree is omitted
 * this allows the construction of a balanced tree
 * in a second call with 'fill_last==1', the last row
 * can be filled
 * idx_ptr is a pointer to an index for data */
void
fill_dbl_bt( double *data, dbl_bt_node_t *node, int* idx_ptr, const int size, unsigned int fill_last ){
  // fill tree left to right
  if( *idx_ptr < size ){
    #ifdef BT_DEBUG
    printf("Trying to assign element %lf\n", data[*idx_ptr]);
    #endif
    assert( node != NULL );
    // the last level needs to be filled at the end
    if( (node->l != NULL && node->r != NULL) || fill_last ){
      if( node->data == NULL ){
        #ifdef BT_DEBUG
        printf("Setting element %lf as data for node %p with parent %p and children l:%p, r:%p\n", 
                data[*idx_ptr], (void*)node, (void*)node->parent, (void*)node->l, (void*)node->r );
        #endif
        node->data = &(data[*idx_ptr]);
        (*idx_ptr)++;
      }
      if( node->l != NULL ){
        #ifdef BT_DEBUG
        printf("Descending into %p->l: %p\n", (void*)node, (void*)node->l );
        #endif
        fill_dbl_bt( data, node->l, idx_ptr, size, fill_last );
      }
      if( node->r != NULL ){
        #ifdef BT_DEBUG
        printf("Descending into %p->r: %p\n", (void*)node, (void*)node->r );
        #endif
        fill_dbl_bt( data, node->r, idx_ptr, size, fill_last );
      }
    }
  }
}

// bt should be a complete binary tree of the right depth,
// otherwise the conditions will fail
void
fill_dbl_bt_complete( dbl_bt_complete_t *bt, double *data, const unsigned int size ){
  int index=0;
  assert( bt->root != NULL );
  assert( pow(2, bt->depth+1)-1 >= size );
  // fill the tree omitting the last row
  fill_dbl_bt( data, bt->root, &index, size, 0 );
  // fill the last row
  fill_dbl_bt( data, bt->root, &index, size, 1 );
}

void
heapify_dbl_bt( dbl_bt_node_t* node ){
  dbl_bt_node_t* largest = node;
  if( node != NULL && node->data != NULL && node->r != NULL && node->l != NULL){
    if( node->l->data != NULL ){
      if( *(node->data) < *(node->l->data) ){
        largest = node->l;
      }
    }
    if( node->r->data != NULL ){
      if( *(largest->data) < *(node->r->data) ){
        largest = node->r;
      }
    }
    if( largest != node ){
      swap_data_dbl_bt( node, largest );
      heapify_dbl_bt( largest );
    }
  }
}

void
make_heap_dbl_bt( dbl_bt_node_t* node ){
  if( node != NULL && node->data != NULL && node->r != NULL && node->l != NULL){
    // recurse all the way to the lowest-1 level
    make_heap_dbl_bt( node->l );
    make_heap_dbl_bt( node->r );
    // heapify depth-first
    heapify_dbl_bt( node );
  }
}

void
free_dbl_heap( dbl_heap_t* heap ){
  free_dbl_bt_complete( heap->bt );
}

// initialise heap by calculating what depth an appropriate complete binary tree has to have
// initialise that tree and fill it with data top to bottom, ensuring that all
// levels except the last are fully filled, thus obtaining a balanced binary tree
dbl_heap_t*
init_dbl_heap( double *data, const unsigned int size ){
  const unsigned int max_depth = ( (unsigned int)log2( (double)size ) );
  #ifdef BT_DEBUG
  printf("The complete binary tree for a heap of size %u has depth %u and can hold %d elements\n",
         size, max_depth, (int)pow(2, max_depth+1)-1 );
  #endif       
  dbl_heap_t* heap = malloc( sizeof(dbl_heap_t) );
  heap->size = size;
  // initialize data structure to hold our binary tree
  heap->bt = init_dbl_bt_complete( max_depth );
  #ifdef BT_DEBUG
  printf("The bottom-left-most and bottom-right-most elements are %p and %p\n", 
         (void*)heap->bt->bottomleft, (void*)heap->bt->bottomright );
  #endif 
  // fill tree with pointers to data
  fill_dbl_bt_complete( heap->bt, data, size );
  // enforce heap property everywhere
  make_heap_dbl_bt( heap->bt->root );
  return heap;
}

void
print_dbl_bt( dbl_bt_node_t* node ){
  assert( node != NULL );
  if( node->data != NULL ){
    printf("%p carries data %lf\n", (void*)node, *(node->data) );
  }
  if( node->l != NULL ) print_dbl_bt( node->l );
  if( node->r != NULL ) print_dbl_bt( node->r );
}

void
swap_data_dbl_bt( dbl_bt_node_t *v1, dbl_bt_node_t *v2 ){
  assert( v1 != NULL && v2 != NULL );
  double *temp = v2->data;
  v2->data = v1->data;
  v1->data = temp;
}

void
swap_node_dbl_bt( dbl_bt_node_t *v1, dbl_bt_node_t *v2 ){
  assert( v1 != NULL && v2 != NULL );
  dbl_bt_node_t temp = *v2;
  *v2 = *v1;
  *v1 = temp;
}

