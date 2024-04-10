#include "Param.hpp"

/*
Type				  | Formatting
----------------------|--------------------------------------------------------------------------------------------
integer					decimal numerical value string (e.g. 421)
bool					1 if true, 0 if false
float					decimal numerical value string, using . as the decimal point separator (e.g. 12.41)
any enumeration			same as integer
integer array			all values are separated by . (e.g. 1.42.51.23 for { 1, 42, 51, 23 })
HSV						{h}a{s}a{v}a{s_checked}a{v_checked}, where each name reflects the respective HSV property
string					raw string without quotation marks (e.g. ExampleString)
*/

std::string Param::colorWhite = "42,1,44,0a0a1a1a1,";
std::string Param::colorRed = "42,1,44,0a0.75a1a1a1,";
std::string Param::colorBlue = "42,1,44,208a0.94a1a1a1,";
std::string Param::colorGreen = "42,1,44,149a0.62a0.72a1a1,";
std::string Param::colorTeal = "42,1,44,192a1a0.4a1a1,";

std::string Param::blackBlending = "22,9,";
std::string Param::noTouch = "155,1,";

std::string Param::halfOpacity = "33,69,";
std::string Param::flipX = "4,1,";
std::string Param::flipY = "5,1,";
std::string Param::halfScaleX = "128,0.5,";

std::string Param::forceHSVException = "__FORCE_HSV_EXCEPTION";

std::string Param::alphaTriggerSetup = "35,0.5,51,69,10,0.0,";
std::string Param::backgroundColorTriggerSetup = "7,130,8,191,9,229,23,1000,";
std::string Param::objectColorTriggerSetup = "7,0,8,0,9,0,23,1004,";
std::string Param::blackBlendingColorTriggerSetup = "17,1,7,0,8,0,9,0,23,9,";

std::string Param::undefinedBlock = "1,0,";

