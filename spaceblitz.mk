##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=spaceblitz
ConfigurationName      :=Debug
WorkspacePath          :=E:/development/cpp_spaceblitz/spaceblitz
ProjectPath            :=E:/development/cpp_spaceblitz/spaceblitz
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=strutinsky5386
Date                   :=02/01/2019
CodeLitePath           :="D:/Program Files/CodeLite"
LinkerName             :=D:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=D:/TDM-GCC-32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="spaceblitz.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)D:\TDM-GCC-32\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)pdcurses 
ArLibs                 :=  "pdcurses" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)D:\TDM-GCC-32\lib $(LibraryPathSwitch)D:\TDM-GCC-32\bin 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := D:/TDM-GCC-32/bin/ar.exe rcu
CXX      := D:/TDM-GCC-32/bin/g++.exe
CC       := D:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/gameconsole.cpp$(ObjectSuffix) $(IntermediateDirectory)/gameengine.cpp$(ObjectSuffix) $(IntermediateDirectory)/vehicles.cpp$(ObjectSuffix) $(IntermediateDirectory)/screeneffects.cpp$(ObjectSuffix) $(IntermediateDirectory)/effects.cpp$(ObjectSuffix) $(IntermediateDirectory)/equipment.cpp$(ObjectSuffix) $(IntermediateDirectory)/gameassetmanager.cpp$(ObjectSuffix) $(IntermediateDirectory)/artassetmanager.cpp$(ObjectSuffix) $(IntermediateDirectory)/ai.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/assetimporter.cpp$(ObjectSuffix) $(IntermediateDirectory)/projectiles.cpp$(ObjectSuffix) $(IntermediateDirectory)/debuglogger.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/gameconsole.cpp$(ObjectSuffix): gameconsole.cpp $(IntermediateDirectory)/gameconsole.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/gameconsole.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gameconsole.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gameconsole.cpp$(DependSuffix): gameconsole.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gameconsole.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gameconsole.cpp$(DependSuffix) -MM gameconsole.cpp

$(IntermediateDirectory)/gameconsole.cpp$(PreprocessSuffix): gameconsole.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gameconsole.cpp$(PreprocessSuffix) gameconsole.cpp

$(IntermediateDirectory)/gameengine.cpp$(ObjectSuffix): gameengine.cpp $(IntermediateDirectory)/gameengine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/gameengine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gameengine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gameengine.cpp$(DependSuffix): gameengine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gameengine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gameengine.cpp$(DependSuffix) -MM gameengine.cpp

$(IntermediateDirectory)/gameengine.cpp$(PreprocessSuffix): gameengine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gameengine.cpp$(PreprocessSuffix) gameengine.cpp

$(IntermediateDirectory)/vehicles.cpp$(ObjectSuffix): vehicles.cpp $(IntermediateDirectory)/vehicles.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/vehicles.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vehicles.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vehicles.cpp$(DependSuffix): vehicles.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vehicles.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/vehicles.cpp$(DependSuffix) -MM vehicles.cpp

$(IntermediateDirectory)/vehicles.cpp$(PreprocessSuffix): vehicles.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vehicles.cpp$(PreprocessSuffix) vehicles.cpp

$(IntermediateDirectory)/screeneffects.cpp$(ObjectSuffix): screeneffects.cpp $(IntermediateDirectory)/screeneffects.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/screeneffects.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/screeneffects.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/screeneffects.cpp$(DependSuffix): screeneffects.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/screeneffects.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/screeneffects.cpp$(DependSuffix) -MM screeneffects.cpp

$(IntermediateDirectory)/screeneffects.cpp$(PreprocessSuffix): screeneffects.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/screeneffects.cpp$(PreprocessSuffix) screeneffects.cpp

$(IntermediateDirectory)/effects.cpp$(ObjectSuffix): effects.cpp $(IntermediateDirectory)/effects.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/effects.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/effects.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/effects.cpp$(DependSuffix): effects.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/effects.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/effects.cpp$(DependSuffix) -MM effects.cpp

$(IntermediateDirectory)/effects.cpp$(PreprocessSuffix): effects.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/effects.cpp$(PreprocessSuffix) effects.cpp

$(IntermediateDirectory)/equipment.cpp$(ObjectSuffix): equipment.cpp $(IntermediateDirectory)/equipment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/equipment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/equipment.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/equipment.cpp$(DependSuffix): equipment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/equipment.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/equipment.cpp$(DependSuffix) -MM equipment.cpp

$(IntermediateDirectory)/equipment.cpp$(PreprocessSuffix): equipment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/equipment.cpp$(PreprocessSuffix) equipment.cpp

$(IntermediateDirectory)/gameassetmanager.cpp$(ObjectSuffix): gameassetmanager.cpp $(IntermediateDirectory)/gameassetmanager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/gameassetmanager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gameassetmanager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gameassetmanager.cpp$(DependSuffix): gameassetmanager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gameassetmanager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gameassetmanager.cpp$(DependSuffix) -MM gameassetmanager.cpp

$(IntermediateDirectory)/gameassetmanager.cpp$(PreprocessSuffix): gameassetmanager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gameassetmanager.cpp$(PreprocessSuffix) gameassetmanager.cpp

$(IntermediateDirectory)/artassetmanager.cpp$(ObjectSuffix): artassetmanager.cpp $(IntermediateDirectory)/artassetmanager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/artassetmanager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/artassetmanager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/artassetmanager.cpp$(DependSuffix): artassetmanager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/artassetmanager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/artassetmanager.cpp$(DependSuffix) -MM artassetmanager.cpp

$(IntermediateDirectory)/artassetmanager.cpp$(PreprocessSuffix): artassetmanager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/artassetmanager.cpp$(PreprocessSuffix) artassetmanager.cpp

$(IntermediateDirectory)/ai.cpp$(ObjectSuffix): ai.cpp $(IntermediateDirectory)/ai.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/ai.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ai.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ai.cpp$(DependSuffix): ai.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ai.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ai.cpp$(DependSuffix) -MM ai.cpp

$(IntermediateDirectory)/ai.cpp$(PreprocessSuffix): ai.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ai.cpp$(PreprocessSuffix) ai.cpp

$(IntermediateDirectory)/assetimporter.cpp$(ObjectSuffix): assetimporter.cpp $(IntermediateDirectory)/assetimporter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/assetimporter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assetimporter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assetimporter.cpp$(DependSuffix): assetimporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assetimporter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/assetimporter.cpp$(DependSuffix) -MM assetimporter.cpp

$(IntermediateDirectory)/assetimporter.cpp$(PreprocessSuffix): assetimporter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assetimporter.cpp$(PreprocessSuffix) assetimporter.cpp

$(IntermediateDirectory)/projectiles.cpp$(ObjectSuffix): projectiles.cpp $(IntermediateDirectory)/projectiles.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/projectiles.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/projectiles.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/projectiles.cpp$(DependSuffix): projectiles.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/projectiles.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/projectiles.cpp$(DependSuffix) -MM projectiles.cpp

$(IntermediateDirectory)/projectiles.cpp$(PreprocessSuffix): projectiles.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/projectiles.cpp$(PreprocessSuffix) projectiles.cpp

$(IntermediateDirectory)/debuglogger.cpp$(ObjectSuffix): debuglogger.cpp $(IntermediateDirectory)/debuglogger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/development/cpp_spaceblitz/spaceblitz/debuglogger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/debuglogger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/debuglogger.cpp$(DependSuffix): debuglogger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/debuglogger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/debuglogger.cpp$(DependSuffix) -MM debuglogger.cpp

$(IntermediateDirectory)/debuglogger.cpp$(PreprocessSuffix): debuglogger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/debuglogger.cpp$(PreprocessSuffix) debuglogger.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


