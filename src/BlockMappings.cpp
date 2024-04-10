#include "BlockMappings.hpp"
#include "Block.hpp"
#include "Param.hpp"
#include "BlockGroup.hpp"

using namespace geode::prelude;

std::vector<BlockGroup*> blockMappings = {
	// WHITE BLOCKS --------------------------------------------
	(new BlockGroup())->add((new Block(216))),
	(new BlockGroup())->add((new Block(207))),
	(new BlockGroup())->add((new Block(212))),
	(new BlockGroup())->add((new Block(208))),
	(new BlockGroup())->add((new Block(209))),
	(new BlockGroup())->add((new Block(213))),
	(new BlockGroup())->add((new Block(211)))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->add((new Block(209)))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->add((new Block(208)))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->add((new Block(208)))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->add((new Block(208)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->add((new Block(211))),
	(new BlockGroup())->add((new Block(207)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	// 16^
	// RED BLOCKS ---------------------------------------------
	(new BlockGroup())->set(Param::colorRed)->add((new Block(207))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(212))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(208))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(209))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(213))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(211)))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(209)))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(208)))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(208)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(208)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(211))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(216))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(207)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	// 33^
	// BLUE BLOCKS ---------------------------------------------
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(207))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(212))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(208))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(209))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(213))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(211)))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(211)))->add((new Block(472)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(209)))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(208)))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(208)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(208)))->add((new Block(472))->set(Param::flipX)->set(Param::flipY))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(211))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(216))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(207)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	// 50^
	// START AND END -------------------------------------------
	(new BlockGroup())->set(Param::colorGreen)->add((new Block(1594))),
	(new BlockGroup())->set(Param::colorGreen)->add((new Block(1153))),
	// 52^
	// LASERS --------------------------------------------------
	(new BlockGroup())->set(Param::halfScaleX)->set(Param::colorWhite)->add(new Block(1144)),
	(new BlockGroup())->set(Param::halfScaleX)->set(Param::colorRed)->add(new Block(1144)),
	(new BlockGroup())->set(Param::halfScaleX)->set(Param::colorBlue)->add(new Block(1144)),
	// 55^
	// CHECKPOINT ----------------------------------------------
	(new BlockGroup())->set(Param::colorTeal)->add(new Block(1594)),
	// 56^
	// DEACTIVATED DEATHS --------------------------------------
	(new BlockGroup())->set(Param::halfOpacity)->add((new Block(207)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	(new BlockGroup())->set(Param::halfOpacity)->set(Param::colorRed)->add((new Block(207)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	(new BlockGroup())->set(Param::halfOpacity)->set(Param::colorBlue)->add((new Block(207)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	// 59^
	// DEACTIVATED SOLIDS --------------------------------------
	(new BlockGroup())->set(Param::halfOpacity)->add((new Block(211))),
	(new BlockGroup())->set(Param::halfOpacity)->set(Param::colorRed)->add((new Block(211))),
	(new BlockGroup())->set(Param::halfOpacity)->set(Param::colorBlue)->add((new Block(211))),
	// 62^
	// OUTLINE BLOCKS ------------------------------------------
	(new BlockGroup())->add(new Block(467)),
	(new BlockGroup())->add(new Block(470)),
	(new BlockGroup())->add(new Block(468)),
	(new BlockGroup())->add(new Block(469)),
	(new BlockGroup())->add(new Block(471)),
	(new BlockGroup())->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->add(new Block(472))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->add(new Block(472))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->add(new Block(472))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->add(new Block(472))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->add(new Block(469))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->add(new Block(468))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->add((new Block(468)))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->add((new Block(468)))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::blackBlending)->add(new Block(216)),
	(new BlockGroup())->add((new Block(467)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	// 78^
	// OUTLINE RED BLOCKS --------------------------------------
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(467)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(470)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(468)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(469)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(471)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(472))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(472))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(472))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(472))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(469))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add(new Block(468))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add((new Block(468)))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add((new Block(468)))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->set(Param::blackBlending)->add(new Block(216)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add((new Block(467)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	// 94^
	// OUTLINE BLUE BLOCKS -------------------------------------
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(467)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(470)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(468)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(469)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(471)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(472))->add((new Block(472))->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(472))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(472))->add((new Block(472))->set(Param::flipX))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(472))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(469))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add(new Block(468))->add((new Block(472))->set(Param::flipX)->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add((new Block(468)))->add((new Block(472))->set(Param::flipY)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add((new Block(468)))->add((new Block(472))->set(Param::flipY))->add((new Block(472))->set(Param::flipY)->set(Param::flipX)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->set(Param::blackBlending)->add(new Block(216)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add((new Block(467)))->add((new Block(665)))->add((new Block(665))->set(Param::flipX)),
	// 110^
	// JUMP PADS ----------------------------------------------
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorWhite)->add((new Block(467))->set(Param::noTouch))->add(new Block(3047)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorRed)->add((new Block(467))->set(Param::noTouch))->add(new Block(3047)),
	(new BlockGroup())->set(Param::forceHSVException)->set(Param::colorBlue)->add((new Block(467))->set(Param::noTouch))->add(new Block(3047)),
	// 113^
	// SLABS --------------------------------------------------
	(new BlockGroup())->add(new Block(1903)),
	(new BlockGroup())->set(Param::colorRed)->add(new Block(1903)),
	(new BlockGroup())->set(Param::colorBlue)->add(new Block(1903)),
	// 116^
	(new BlockGroup())->add((new Block(1905))->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(1905))->set(Param::flipX)),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(1905))->set(Param::flipX)),
	// 122^
	(new BlockGroup())->add((new Block(1905))),
	(new BlockGroup())->set(Param::colorRed)->add((new Block(1905))),
	(new BlockGroup())->set(Param::colorBlue)->add((new Block(1905))),
	// 125^
	(new BlockGroup())->add(new Block(1904)),
	(new BlockGroup())->set(Param::colorRed)->add(new Block(1904)),
	(new BlockGroup())->set(Param::colorBlue)->add(new Block(1904)),
};


