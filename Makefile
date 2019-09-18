# Nakefile created by zefengwang
# test on centos 7 (x86_64)
# with gcc version 4.8.5


all:
	$(MAKE) -C ch02
	$(MAKE) -C ch03
	$(MAKE) -C ch04
	$(MAKE) -C ch05
	$(MAKE) -C ch06

.PHONY: clean
clean:
	$(MAKE) clean -C ch02
	$(MAKE) clean -C ch03
	$(MAKE) clean -C ch04
	$(MAKE) clean -C ch05
	$(MAKE) clean -C ch06

