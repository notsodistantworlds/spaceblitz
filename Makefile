.PHONY: clean All

All:
	@echo "----------Building project:[ spaceblitz - Debug ]----------"
	@"$(MAKE)" -f  "spaceblitz.mk"
clean:
	@echo "----------Cleaning project:[ spaceblitz - Debug ]----------"
	@"$(MAKE)" -f  "spaceblitz.mk" clean
