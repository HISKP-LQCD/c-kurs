#ifndef DBL_BINTREE_H
#define DBL_BINTREE_H

typedef struct dbl_bt_node_t {
  double *data;
  struct dbl_bt_node_t *parent;
  struct dbl_bt_node_t *l;
  struct dbl_bt_node_t *r;
} dbl_bt_node_t;

/* a complete binary tree has 2^(depth+1)-1 nodes,
 * and all levels except the last one are fully filled,
 * we can determine which node is at the bottom left
 * and which node is at the bottom right */
typedef struct dbl_bt_complete_t {
  dbl_bt_node_t *root;
  dbl_bt_node_t *bottomright;
  dbl_bt_node_t *bottomleft;
  unsigned int depth;
} dbl_bt_complete_t;

/* a heap is a (possibly) partly filled complete binary tree
 * with a strict ordering between parents and their children
 * the binary tree has a certain depth, which depends on the size
 * of the heap */
typedef struct dbl_heap_t {
  dbl_bt_complete_t *bt;
  unsigned int size;
} dbl_heap_t;

dbl_bt_complete_t* init_dbl_bt_complete( const unsigned int depth );

void free_dbl_bt_complete( dbl_bt_complete_t* bt );

void free_dbl_heap( dbl_heap_t* heap );

dbl_bt_node_t dbl_bt_complete_fill(dbl_bt_complete_t *bt, double *data, unsigned int n );

void heapify_dbl_bt( dbl_bt_node_t* node );

void make_heap_dbl_bt( dbl_bt_node_t* node );

void print_dbl_bt( dbl_bt_node_t* node );

dbl_bt_node_t*
find_tail_node_dbl_bt( dbl_bt_node_t* node );

void
dbl_bt_descend( dbl_bt_node_t **node, dbl_bt_node_t *parent, const unsigned int depth );

dbl_heap_t *
init_dbl_heap( double *data, const unsigned int size );

void
swap_data_dbl_bt( dbl_bt_node_t *v1, dbl_bt_node_t *v2 );

void
swap_node_dbl_bt( dbl_bt_node_t *v1, dbl_bt_node_t *v2 );

#endif // ifdef(DBL_BINTREE_H)
