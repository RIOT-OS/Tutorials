SRC := slides.md
SCRIPTDIR=scripts
FILENAME := tutorial-slides
DEPS := preamble-caption.tex
PDFLAGS := -s -S -t beamer --latex-engine=xelatex --slide-level=2
PDFLAGS += --filter=$(SCRIPTDIR)/pandoc-svg
PDFLAGS += --filter=$(SCRIPTDIR)/overlay
DEPS += $(patsubst %.svg,%.pdf,$(wildcard pictures/6lowpan-route-over*.svg)\
							   $(wildcard pictures/overview-net*.svg)\
							   $(wildcard pictures/exp-setup*.svg))
DEPS += pictures/gnrc-arch-netif.pdf

ifneq (,$(wildcard template.tex))
  PDFLAGS += --template=template.tex
  DEPS += template.tex
endif

ifeq (,$(shell type pandoc 2> /dev/null))
  $(error Need `pandoc` (including python-lib pandocfilters) to compile)
endif

.PHONY: all clean

all: $(FILENAME).pdf

$(FILENAME).pdf: $(SRC) $(DEPS)
	pandoc $(foreach H,$(filter preamble-%.tex,$^),-H $(H))\
	       $(foreach B,$(filter before-%.tex,$^),-B $(B)) -o $@ $(PDFLAGS) $<

pictures/%.pdf: pictures/%.svg
	inkscape --export-pdf=$@ $<

clean:
	rm -f $(FILENAME)* $(filter pictures/%.pdf,$(DEPS)) \
		  $(patsubst %.psvg,%,$(wildcard pictures/*.psvg)) \
		  $(wildcard pictures/*.psvg)
