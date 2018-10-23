# Build the NEC2DXS executable with g77.

FC := g77
FCFLAGS := -O
PROGRAMS := nec2dxs

all: $(PROGRAMS)

nec2dxs: nec2dxs.f
	$(FC) $(FCFLAGS)  nec2dxs.f -o nec2dxs

clean:
	rm $(PROGRAMS)
