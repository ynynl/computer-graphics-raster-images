# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.raster.Debug:
/Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/Debug/raster:
	/bin/rm -f /Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/Debug/raster


PostBuild.raster.Release:
/Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/Release/raster:
	/bin/rm -f /Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/Release/raster


PostBuild.raster.MinSizeRel:
/Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/MinSizeRel/raster:
	/bin/rm -f /Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/MinSizeRel/raster


PostBuild.raster.RelWithDebInfo:
/Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/RelWithDebInfo/raster:
	/bin/rm -f /Users/yinyinlu/OneDrive\ -\ University\ of\ Toronto/Projects/ComputerGraphic/computer-graphics-raster-images/xcodeBuild/RelWithDebInfo/raster




# For each target create a dummy ruleso the target does not have to exist
