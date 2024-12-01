objects = main.o 
	algorithm_analysis.o 
	table_stack_queue.o

%.o: %.c
	gcc -o $@ -c $<
%.o: ./chapter_2/%.c
	gcc -o $@ -c $<	
%.o: ./chapter_3/%.c
	gcc -o $@ -c $<	

al_ds: ${objects}
	gcc -o al_ds ${objects}
	@find . -name "*.o" -delete
	
clean: 
	@find . -name "*.o" -delete
	@echo 'clean success.'