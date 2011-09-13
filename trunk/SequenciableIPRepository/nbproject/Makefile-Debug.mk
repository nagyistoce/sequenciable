#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/HomomorphicFilter.o \
	${OBJECTDIR}/HomomorphicFilterHSV.o \
	${OBJECTDIR}/HSV2HSVVec.o \
	${OBJECTDIR}/HSVColor.o \
	${OBJECTDIR}/RGBtoLABTransform.o \
	${OBJECTDIR}/LABtoRGBTransform.o \
	${OBJECTDIR}/homomorphic_opencv.o \
	${OBJECTDIR}/HSVtoRGBTransform.o \
	${OBJECTDIR}/HSVVecEvent.o \
	${OBJECTDIR}/RGBtoHSVTransform.o \
	${OBJECTDIR}/IplEvent.o \
	${OBJECTDIR}/SmoothFilter.o \
	${OBJECTDIR}/HSVColorClusterEstimation.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciableiprepository.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciableiprepository.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciableiprepository.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciableiprepository.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciableiprepository.a

${OBJECTDIR}/HomomorphicFilter.o: HomomorphicFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilter.o HomomorphicFilter.cpp

${OBJECTDIR}/HomomorphicFilterHSV.o: HomomorphicFilterHSV.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilterHSV.o HomomorphicFilterHSV.cpp

${OBJECTDIR}/HSV2HSVVec.o: HSV2HSVVec.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSV2HSVVec.o HSV2HSVVec.cpp

${OBJECTDIR}/HSVColor.o: HSVColor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVColor.o HSVColor.cpp

${OBJECTDIR}/RGBtoLABTransform.o: RGBtoLABTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/RGBtoLABTransform.o RGBtoLABTransform.cpp

${OBJECTDIR}/LABtoRGBTransform.o: LABtoRGBTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/LABtoRGBTransform.o LABtoRGBTransform.cpp

${OBJECTDIR}/homomorphic_opencv.o: homomorphic_opencv.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/homomorphic_opencv.o homomorphic_opencv.cpp

${OBJECTDIR}/HSVtoRGBTransform.o: HSVtoRGBTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVtoRGBTransform.o HSVtoRGBTransform.cpp

${OBJECTDIR}/HSVVecEvent.o: HSVVecEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVVecEvent.o HSVVecEvent.cpp

${OBJECTDIR}/RGBtoHSVTransform.o: RGBtoHSVTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/RGBtoHSVTransform.o RGBtoHSVTransform.cpp

${OBJECTDIR}/IplEvent.o: IplEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/IplEvent.o IplEvent.cpp

${OBJECTDIR}/SmoothFilter.o: SmoothFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/SmoothFilter.o SmoothFilter.cpp

${OBJECTDIR}/HSVColorClusterEstimation.o: HSVColorClusterEstimation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/C/workspace/OpenCVMinGW/install/include/opencv -I/C/workspace/OpenCVMinGW/install/include -I. -I/C/Users/Claudio/workspace/Sequenciables -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVColorClusterEstimation.o HSVColorClusterEstimation.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciableiprepository.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
