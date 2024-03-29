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
CND_CONF=ReleaseLinux
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sequence.o \
	${OBJECTDIR}/NoOutputReachableException.o \
	${OBJECTDIR}/Event.o \
	${OBJECTDIR}/IncompatibleClassesException.o \
	${OBJECTDIR}/ShortCircuitException.o \
	${OBJECTDIR}/SequenciableOutOfRangeException.o \
	${OBJECTDIR}/Sequenciable.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciables.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciables.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciables.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciables.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciables.a

${OBJECTDIR}/Sequence.o: Sequence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -w -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sequence.o Sequence.cpp

${OBJECTDIR}/NoOutputReachableException.o: NoOutputReachableException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -w -MMD -MP -MF $@.d -o ${OBJECTDIR}/NoOutputReachableException.o NoOutputReachableException.cpp

${OBJECTDIR}/Event.o: Event.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -w -MMD -MP -MF $@.d -o ${OBJECTDIR}/Event.o Event.cpp

${OBJECTDIR}/IncompatibleClassesException.o: IncompatibleClassesException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -w -MMD -MP -MF $@.d -o ${OBJECTDIR}/IncompatibleClassesException.o IncompatibleClassesException.cpp

${OBJECTDIR}/ShortCircuitException.o: ShortCircuitException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -w -MMD -MP -MF $@.d -o ${OBJECTDIR}/ShortCircuitException.o ShortCircuitException.cpp

${OBJECTDIR}/SequenciableOutOfRangeException.o: SequenciableOutOfRangeException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -w -MMD -MP -MF $@.d -o ${OBJECTDIR}/SequenciableOutOfRangeException.o SequenciableOutOfRangeException.cpp

${OBJECTDIR}/Sequenciable.o: Sequenciable.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O3 -w -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sequenciable.o Sequenciable.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsequenciables.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
