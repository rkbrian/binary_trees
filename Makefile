# memo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
PTREE = binary_tree_print.c
NNODE = 0-binary_tree_node.c
INSN = 2-binary_tree_insert_right.c
DELN = 3-binary_tree_delete.c
BALA = 14-binary_tree_balance.c
ROTA = 103-binary_tree_rotate_left.c 104-binary_tree_rotate_right.c
# mandatory tasks
0-node: 	$(PTREE) $(NNODE) 0-main.c
	$(CC) $(CFLAGS) $^ -o $@
1-left: 	$(PTREE) $(NNODE) 1-main.c 1-binary_tree_insert_left.c
	$(CC) $(CFLAGS) $^ -o $@
2-right: 	$(PTREE) $(NNODE) $(INSN) 2-main.c
	$(CC) $(CFLAGS) $^ -o $@
3-del: 		$(PTREE) $(NNODE) $(INSN) $(DELN) 3-main.c
	$(CC) $(CFLAGS) $^ -o $@
4-leaf: 	$(PTREE) $(NNODE) $(INSN) 4-binary_tree_is_leaf.c 4-main.c
	$(CC) $(CFLAGS) $^ -o $@
5-root: 	$(PTREE) $(NNODE) $(INSN) 5-binary_tree_is_root.c 5-main.c
	$(CC) $(CFLAGS) $^ -o $@
6-pre: 		$(PTREE) $(NNODE) 6-main.c 6-binary_tree_preorder.c
	$(CC) $(CFLAGS) $^ -o $@
7-in: 		$(PTREE) $(NNODE) 7-main.c 7-binary_tree_inorder.c
	$(CC) $(CFLAGS) $^ -o $@
8-post: 	$(PTREE) $(NNODE) 8-main.c 8-binary_tree_postorder.c
	$(CC) $(CFLAGS) $^ -o $@
9-height: 	$(PTREE) $(NNODE) $(INSN) 9-binary_tree_height.c 9-main.c
	$(CC) $(CFLAGS) $^ -o $@
10-depth: 	$(PTREE) $(NNODE) $(INSN) 10-binary_tree_depth.c 10-main.c
	$(CC) $(CFLAGS) $^ -o $@
11-size: 	$(PTREE) $(NNODE) $(INSN) 11-binary_tree_size.c 11-main.c
	$(CC) $(CFLAGS) $^ -o $@
12-leaves: 	$(PTREE) $(NNODE) $(INSN) 12-binary_tree_leaves.c 12-main.c
	$(CC) $(CFLAGS) $^ -o $@
13-nodes: 	$(PTREE) $(NNODE) $(INSN) 13-binary_tree_nodes.c 13-main.c
	$(CC) $(CFLAGS) $^ -o $@
14-balance: 	$(PTREE) $(NNODE) $(INSN) $(BALA) 14-main.c 1-binary_tree_insert_left.c
	$(CC) $(CFLAGS) $^ -o $@
15-full: 	$(PTREE) $(NNODE) $(INSN) 15-binary_tree_is_full.c 15-main.c
	$(CC) $(CFLAGS) $^ -o $@
16-perfect: 	$(PTREE) $(NNODE) $(INSN) 16-binary_tree_is_perfect.c 16-main.c
	$(CC) $(CFLAGS) $^ -o $@
17-sibling: 	$(PTREE) $(NNODE) 17-main.c 17-binary_tree_sibling.c
	$(CC) $(CFLAGS) $^ -o $@
18-uncle: 	$(PTREE) $(NNODE) 18-main.c 18-binary_tree_uncle.c
	$(CC) $(CFLAGS) $^ -o $@
# advanced tasks
100-ancestor: 	$(PTREE) $(NNODE) 100-main.c 100-binary_trees_ancestor.c
	$(CC) $(CFLAGS) $^ -o $@
101-lvl: 	$(PTREE) $(NNODE) $(DELN) 101-main.c 101-binary_tree_levelorder.c
	$(CC) $(CFLAGS) $^ -o $@
102-complete: 	$(PTREE) $(NNODE) $(DELN) 102-main.c 102-binary_tree_is_complete.c
	$(CC) $(CFLAGS) $^ -o $@
103-rotl: 	$(PTREE) $(NNODE) 103-binary_tree_rotate_left.c 103-main.c
	$(CC) $(CFLAGS) $^ -o $@
104-rotr: 	$(PTREE) $(NNODE) 104-binary_tree_rotate_right.c 104-main.c
	$(CC) $(CFLAGS) $^ -o $@
110-is_bst: 	$(PTREE) $(NNODE) 110-main.c 110-binary_tree_is_bst.c
	$(CC) $(CFLAGS) $^ -o $@
111-bst_insert: $(PTREE) $(NNODE) 111-bst_insert.c 111-main.c
	$(CC) $(CFLAGS) $^ -o $@
112-bst_array: 	$(PTREE) $(NNODE) 112-array_to_bst.c 112-main.c 111-bst_insert.c
	$(CC) $(CFLAGS) $^ -o $@
113-bst_search: $(PTREE) $(NNODE) 113-bst_search.c 113-main.c 112-array_to_bst.c 111-bst_insert.c
	$(CC) $(CFLAGS) $^ -o $@
114-bst_rm: 	$(PTREE) $(NNODE) $(DELN) 114-bst_remove.c 114-main.c 112-array_to_bst.c 111-bst_insert.c
	$(CC) $(CFLAGS) $^ -o $@
120-is_avl: 	$(PTREE) $(NNODE) 120-main.c 120-binary_tree_is_avl.c
	$(CC) $(CFLAGS) $^ -o $@
121-avl_insert: $(PTREE) $(NNODE) $(BALA) $(ROTA) 121-avl_insert.c 121-main.c
	$(CC) $(CFLAGS) $^ -o $@
122-avl_array:	$(PTREE) $(NNODE) $(BALA) $(ROTA) 122-array_to_avl.c 122-main.c 121-avl_insert.c
	$(CC) $(CFLAGS) $^ -o $@
# still working on
123-avl_rm:	$(PTREE) $(NNODE) $(DELN) $(BALA) $(ROTA) 123-avl_remove.c 123-main.c 122-array_to_avl.c 121-avl_insert.c
	$(CC) $(CFLAGS) $^ -o $@
