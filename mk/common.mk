# Bash color codes
CLR_RD 		= \033[0;31m
CLR_GR 	= \033[0;32m
CLR_YL 	= \033[0;33m
CLR_CY 	    = \033[0;36m
CLR_NC 		= \033[0m

.PHONY : help
help : Makefile						## Show help message
	@echo "***** Makefile help *****"
	@echo "Usage:"
	@echo "	$$ make [TARGET]"
	@echo "TARGETs:"
	@grep -Eh '\s##\s' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\t$(CLR_CY)%-20s$(CLR_NC) %s\n", $$1, $$2}'
	@echo ""
	@sed -n 's/^#f //p' Makefile