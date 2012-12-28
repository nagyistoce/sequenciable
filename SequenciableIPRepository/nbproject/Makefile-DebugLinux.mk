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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=DebugLinux
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
	${OBJECTDIR}/HomomorphicFilterLAB.o \
	${OBJECTDIR}/SRMSegmentation.o \
	${OBJECTDIR}/RGBtoLABTransform.o \
	${OBJECTDIR}/MeanShift.o \
	${OBJECTDIR}/homomorphic_opencv.o \
	${OBJECTDIR}/KMeansColorReduction.o \
	${OBJECTDIR}/LABtoRGBTransform.o \
	${OBJECTDIR}/HSVtoRGBTransform.o \
	${OBJECTDIR}/HSVVecEvent.o \
	${OBJECTDIR}/ContrastBrigthness.o \
	${OBJECTDIR}/RGBtoHSVTransform.o \
	${OBJECTDIR}/IplEvent.o \
	${OBJECTDIR}/SmoothFilter.o \
	${OBJECTDIR}/HSVColorClusterEstimation.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilter.o HomomorphicFilter.cpp

${OBJECTDIR}/HomomorphicFilterHSV.o: HomomorphicFilterHSV.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilterHSV.o HomomorphicFilterHSV.cpp

${OBJECTDIR}/HSV2HSVVec.o: HSV2HSVVec.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSV2HSVVec.o HSV2HSVVec.cpp

${OBJECTDIR}/HSVColor.o: HSVColor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVColor.o HSVColor.cpp

${OBJECTDIR}/HomomorphicFilterLAB.o: HomomorphicFilterLAB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilterLAB.o HomomorphicFilterLAB.cpp

${OBJECTDIR}/SRMSegmentation.o: SRMSegmentation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/SRMSegmentation.o SRMSegmentation.cpp

${OBJECTDIR}/RGBtoLABTransform.o: RGBtoLABTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/RGBtoLABTransform.o RGBtoLABTransform.cpp

${OBJECTDIR}/MeanShift.o: MeanShift.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/MeanShift.o MeanShift.cpp

${OBJECTDIR}/homomorphic_opencv.o: homomorphic_opencv.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/homomorphic_opencv.o homomorphic_opencv.cpp

${OBJECTDIR}/KMeansColorReduction.o: KMeansColorReduction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/KMeansColorReduction.o KMeansColorReduction.cpp

${OBJECTDIR}/LABtoRGBTransform.o: LABtoRGBTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/LABtoRGBTransform.o LABtoRGBTransform.cpp

${OBJECTDIR}/HSVtoRGBTransform.o: HSVtoRGBTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVtoRGBTransform.o HSVtoRGBTransform.cpp

${OBJECTDIR}/HSVVecEvent.o: HSVVecEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVVecEvent.o HSVVecEvent.cpp

${OBJECTDIR}/ContrastBrigthness.o: ContrastBrigthness.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/ContrastBrigthness.o ContrastBrigthness.cpp

${OBJECTDIR}/RGBtoHSVTransform.o: RGBtoHSVTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/RGBtoHSVTransform.o RGBtoHSVTransform.cpp

${OBJECTDIR}/IplEvent.o: IplEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/IplEvent.o IplEvent.cpp

${OBJECTDIR}/SmoothFilter.o: SmoothFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/SmoothFilter.o SmoothFilter.cpp

${OBJECTDIR}/HSVColorClusterEstimation.o: HSVColorClusterEstimation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVColorClusterEstimation.o HSVColorClusterEstimation.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/168602167/newtestclass.o ${TESTDIR}/_ext/168602167/newtestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -L../Sequenciables/dist/DebugLinux/GNU-Linux-x86 -L/usr/local/lib -lcppunit -lcv -lcxcore -lhighgui -lsequenciables 


${TESTDIR}/_ext/168602167/newtestclass.o: /home/claudio/NetBeansProjects/Sequenciables/SequenciableIPRepository/tests/newtestclass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/168602167
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I. -I. -I. -I. -I. -I. -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/168602167/newtestclass.o /home/claudio/NetBeansProjects/Sequenciables/SequenciableIPRepository/tests/newtestclass.cpp


${TESTDIR}/_ext/168602167/newtestrunner.o: /home/claudio/NetBeansProjects/Sequenciables/SequenciableIPRepository/tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/168602167
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I. -I. -I. -I. -I. -I. -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/168602167/newtestrunner.o /home/claudio/NetBeansProjects/Sequenciables/SequenciableIPRepository/tests/newtestrunner.cpp


${OBJECTDIR}/HomomorphicFilter_nomain.o: ${OBJECTDIR}/HomomorphicFilter.o HomomorphicFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HomomorphicFilter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilter_nomain.o HomomorphicFilter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HomomorphicFilter.o ${OBJECTDIR}/HomomorphicFilter_nomain.o;\
	fi

${OBJECTDIR}/HomomorphicFilterHSV_nomain.o: ${OBJECTDIR}/HomomorphicFilterHSV.o HomomorphicFilterHSV.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HomomorphicFilterHSV.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilterHSV_nomain.o HomomorphicFilterHSV.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HomomorphicFilterHSV.o ${OBJECTDIR}/HomomorphicFilterHSV_nomain.o;\
	fi

${OBJECTDIR}/HSV2HSVVec_nomain.o: ${OBJECTDIR}/HSV2HSVVec.o HSV2HSVVec.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HSV2HSVVec.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSV2HSVVec_nomain.o HSV2HSVVec.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HSV2HSVVec.o ${OBJECTDIR}/HSV2HSVVec_nomain.o;\
	fi

${OBJECTDIR}/HSVColor_nomain.o: ${OBJECTDIR}/HSVColor.o HSVColor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HSVColor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVColor_nomain.o HSVColor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HSVColor.o ${OBJECTDIR}/HSVColor_nomain.o;\
	fi

${OBJECTDIR}/HomomorphicFilterLAB_nomain.o: ${OBJECTDIR}/HomomorphicFilterLAB.o HomomorphicFilterLAB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HomomorphicFilterLAB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HomomorphicFilterLAB_nomain.o HomomorphicFilterLAB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HomomorphicFilterLAB.o ${OBJECTDIR}/HomomorphicFilterLAB_nomain.o;\
	fi

${OBJECTDIR}/SRMSegmentation_nomain.o: ${OBJECTDIR}/SRMSegmentation.o SRMSegmentation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SRMSegmentation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/SRMSegmentation_nomain.o SRMSegmentation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SRMSegmentation.o ${OBJECTDIR}/SRMSegmentation_nomain.o;\
	fi

${OBJECTDIR}/RGBtoLABTransform_nomain.o: ${OBJECTDIR}/RGBtoLABTransform.o RGBtoLABTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RGBtoLABTransform.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RGBtoLABTransform_nomain.o RGBtoLABTransform.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RGBtoLABTransform.o ${OBJECTDIR}/RGBtoLABTransform_nomain.o;\
	fi

${OBJECTDIR}/MeanShift_nomain.o: ${OBJECTDIR}/MeanShift.o MeanShift.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MeanShift.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MeanShift_nomain.o MeanShift.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MeanShift.o ${OBJECTDIR}/MeanShift_nomain.o;\
	fi

${OBJECTDIR}/homomorphic_opencv_nomain.o: ${OBJECTDIR}/homomorphic_opencv.o homomorphic_opencv.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/homomorphic_opencv.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/homomorphic_opencv_nomain.o homomorphic_opencv.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/homomorphic_opencv.o ${OBJECTDIR}/homomorphic_opencv_nomain.o;\
	fi

${OBJECTDIR}/KMeansColorReduction_nomain.o: ${OBJECTDIR}/KMeansColorReduction.o KMeansColorReduction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/KMeansColorReduction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/KMeansColorReduction_nomain.o KMeansColorReduction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/KMeansColorReduction.o ${OBJECTDIR}/KMeansColorReduction_nomain.o;\
	fi

${OBJECTDIR}/LABtoRGBTransform_nomain.o: ${OBJECTDIR}/LABtoRGBTransform.o LABtoRGBTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LABtoRGBTransform.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/LABtoRGBTransform_nomain.o LABtoRGBTransform.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LABtoRGBTransform.o ${OBJECTDIR}/LABtoRGBTransform_nomain.o;\
	fi

${OBJECTDIR}/HSVtoRGBTransform_nomain.o: ${OBJECTDIR}/HSVtoRGBTransform.o HSVtoRGBTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HSVtoRGBTransform.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVtoRGBTransform_nomain.o HSVtoRGBTransform.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HSVtoRGBTransform.o ${OBJECTDIR}/HSVtoRGBTransform_nomain.o;\
	fi

${OBJECTDIR}/HSVVecEvent_nomain.o: ${OBJECTDIR}/HSVVecEvent.o HSVVecEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HSVVecEvent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVVecEvent_nomain.o HSVVecEvent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HSVVecEvent.o ${OBJECTDIR}/HSVVecEvent_nomain.o;\
	fi

${OBJECTDIR}/ContrastBrigthness_nomain.o: ${OBJECTDIR}/ContrastBrigthness.o ContrastBrigthness.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ContrastBrigthness.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/ContrastBrigthness_nomain.o ContrastBrigthness.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ContrastBrigthness.o ${OBJECTDIR}/ContrastBrigthness_nomain.o;\
	fi

${OBJECTDIR}/RGBtoHSVTransform_nomain.o: ${OBJECTDIR}/RGBtoHSVTransform.o RGBtoHSVTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RGBtoHSVTransform.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RGBtoHSVTransform_nomain.o RGBtoHSVTransform.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RGBtoHSVTransform.o ${OBJECTDIR}/RGBtoHSVTransform_nomain.o;\
	fi

${OBJECTDIR}/IplEvent_nomain.o: ${OBJECTDIR}/IplEvent.o IplEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IplEvent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/IplEvent_nomain.o IplEvent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/IplEvent.o ${OBJECTDIR}/IplEvent_nomain.o;\
	fi

${OBJECTDIR}/SmoothFilter_nomain.o: ${OBJECTDIR}/SmoothFilter.o SmoothFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SmoothFilter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/SmoothFilter_nomain.o SmoothFilter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SmoothFilter.o ${OBJECTDIR}/SmoothFilter_nomain.o;\
	fi

${OBJECTDIR}/HSVColorClusterEstimation_nomain.o: ${OBJECTDIR}/HSVColorClusterEstimation.o HSVColorClusterEstimation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HSVColorClusterEstimation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -I/usr/local/include/opencv -I/usr/local/include -I/home/claudio/NetBeansProjects/Sequenciables/Sequenciables -I/home/claudio/NetBeansProjects/ColorSegmentatorDiscover/MeanShiftEDISON -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/HSVColorClusterEstimation_nomain.o HSVColorClusterEstimation.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HSVColorClusterEstimation.o ${OBJECTDIR}/HSVColorClusterEstimation_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciableiprepository.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
