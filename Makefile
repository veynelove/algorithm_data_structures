objects = main.o \
	algorithm_analysis.o \
	polynomial_adt.o \
	avl_tree.o \
	hashing.o \
	open_addressing_hashing.o \
	leftist_heap.o \
	binomial_queue.o
#priority_queue.o
#separate_chaining.o
#search_tree.o
#list.o
#queue_by_array.o
#stack_by_array.o 
#stack_by_list.o 不支持函数重载,链接函数名会与list.h中冲突.因学习需要,不加入编译

%.o: %.c
	gcc -o $@ -c $< 
%.o: ./chapter_2/%.c
	gcc -o $@ -c $<	
%.o: ./chapter_3/%.c
	gcc -o $@ -c $<	
%.o: ./chapter_4/%.c
	gcc -o $@ -c $<	
%.o: ./chapter_5/%.c
	gcc -o $@ -c $<	
%.o: ./chapter_6/%.c
	gcc -o $@ -c $<	

al_ds: ${objects}
	gcc -o al_ds ${objects} -lm
	@find . -name "*.o" -delete
	
clean: 
	@find . -name "*.o" -delete
	@echo 'clean success.'