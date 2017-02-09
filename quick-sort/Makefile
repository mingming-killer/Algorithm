#This Makefile is created by mingming-killer
 
SRCS := $(wildcard *.c)
DEPS := $(SRCS:.c=.d)
OBJS := $(SRCS:.c=.o)
 
APP = app.out
   
CC = gcc
#LDFLAGS = `pkg-config --libs gstreamer-0.10` -L$(LIB_PATH) $(LIBS)
#CFLAGS = `pkg-config --cflags gstreamer-0.10` -I$(INCLUDE_PATH)
LDFLAGS = 
CFLAGS = 
#LIBS = -lpthread 
LIBS =  
LIB_PATH = /usr/local/lib
INCLUDE_PATH = /usr/local/include


# if "make clean" do not create the depend file
ifneq ($(MAKECMDGOALS), clean)

%d: %c
	$(CC) -MM $< > $@

endif


$(APP): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


-include $(DEPS)


.PHONY: clean 
clean:
	-rm -f debug $(APP) $(wildcard *.o ./tmp/*.d *.d *~)
	@echo "it is cleaning."

