APPS_GRC_FILES = $(shell find apps/ -maxdepth 1 -type f -name '*.grc')
APPS_PY_FILES = $(patsubst apps/%.grc, apps/%.py, $(APPS_GRC_FILES))

build: $(APPS_PY_FILES)

apps/%.py: apps/%.grc
	@python3 -c "import timingsync"$
	grcc $< -o $(@D)
