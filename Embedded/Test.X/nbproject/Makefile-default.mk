#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../carte_moteur_Guerin_Herveleu.X/ADC.c ../carte_moteur_Guerin_Herveleu.X/CB_RX1.c ../carte_moteur_Guerin_Herveleu.X/CB_TX1.c ../carte_moteur_Guerin_Herveleu.X/ChipConfig.c ../carte_moteur_Guerin_Herveleu.X/IO.c ../carte_moteur_Guerin_Herveleu.X/PWM.c ../carte_moteur_Guerin_Herveleu.X/Robot.c ../carte_moteur_Guerin_Herveleu.X/ToolBox.c ../carte_moteur_Guerin_Herveleu.X/UART.c ../carte_moteur_Guerin_Herveleu.X/brouillonstrat.c ../carte_moteur_Guerin_Herveleu.X/main.c ../carte_moteur_Guerin_Herveleu.X/timer.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/190710523/ADC.o ${OBJECTDIR}/_ext/190710523/CB_RX1.o ${OBJECTDIR}/_ext/190710523/CB_TX1.o ${OBJECTDIR}/_ext/190710523/ChipConfig.o ${OBJECTDIR}/_ext/190710523/IO.o ${OBJECTDIR}/_ext/190710523/PWM.o ${OBJECTDIR}/_ext/190710523/Robot.o ${OBJECTDIR}/_ext/190710523/ToolBox.o ${OBJECTDIR}/_ext/190710523/UART.o ${OBJECTDIR}/_ext/190710523/brouillonstrat.o ${OBJECTDIR}/_ext/190710523/main.o ${OBJECTDIR}/_ext/190710523/timer.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/190710523/ADC.o.d ${OBJECTDIR}/_ext/190710523/CB_RX1.o.d ${OBJECTDIR}/_ext/190710523/CB_TX1.o.d ${OBJECTDIR}/_ext/190710523/ChipConfig.o.d ${OBJECTDIR}/_ext/190710523/IO.o.d ${OBJECTDIR}/_ext/190710523/PWM.o.d ${OBJECTDIR}/_ext/190710523/Robot.o.d ${OBJECTDIR}/_ext/190710523/ToolBox.o.d ${OBJECTDIR}/_ext/190710523/UART.o.d ${OBJECTDIR}/_ext/190710523/brouillonstrat.o.d ${OBJECTDIR}/_ext/190710523/main.o.d ${OBJECTDIR}/_ext/190710523/timer.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/190710523/ADC.o ${OBJECTDIR}/_ext/190710523/CB_RX1.o ${OBJECTDIR}/_ext/190710523/CB_TX1.o ${OBJECTDIR}/_ext/190710523/ChipConfig.o ${OBJECTDIR}/_ext/190710523/IO.o ${OBJECTDIR}/_ext/190710523/PWM.o ${OBJECTDIR}/_ext/190710523/Robot.o ${OBJECTDIR}/_ext/190710523/ToolBox.o ${OBJECTDIR}/_ext/190710523/UART.o ${OBJECTDIR}/_ext/190710523/brouillonstrat.o ${OBJECTDIR}/_ext/190710523/main.o ${OBJECTDIR}/_ext/190710523/timer.o

# Source Files
SOURCEFILES=../carte_moteur_Guerin_Herveleu.X/ADC.c ../carte_moteur_Guerin_Herveleu.X/CB_RX1.c ../carte_moteur_Guerin_Herveleu.X/CB_TX1.c ../carte_moteur_Guerin_Herveleu.X/ChipConfig.c ../carte_moteur_Guerin_Herveleu.X/IO.c ../carte_moteur_Guerin_Herveleu.X/PWM.c ../carte_moteur_Guerin_Herveleu.X/Robot.c ../carte_moteur_Guerin_Herveleu.X/ToolBox.c ../carte_moteur_Guerin_Herveleu.X/UART.c ../carte_moteur_Guerin_Herveleu.X/brouillonstrat.c ../carte_moteur_Guerin_Herveleu.X/main.c ../carte_moteur_Guerin_Herveleu.X/timer.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512GM306
MP_LINKER_FILE_OPTION=,--script=p33EP512GM306.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/190710523/ADC.o: ../carte_moteur_Guerin_Herveleu.X/ADC.c  .generated_files/flags/default/df9994030e117cfd26f22a98b44e3d4bd0f6d888 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/ADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/ADC.c  -o ${OBJECTDIR}/_ext/190710523/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/ADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/CB_RX1.o: ../carte_moteur_Guerin_Herveleu.X/CB_RX1.c  .generated_files/flags/default/7b2ae2ec9677c7f91b2d19c69402711b1b616ad0 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_RX1.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_RX1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/CB_RX1.c  -o ${OBJECTDIR}/_ext/190710523/CB_RX1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/CB_RX1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/CB_TX1.o: ../carte_moteur_Guerin_Herveleu.X/CB_TX1.c  .generated_files/flags/default/d79c1f0e09f9ec04cf98e0b45d2adc2e8b6033c4 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_TX1.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_TX1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/CB_TX1.c  -o ${OBJECTDIR}/_ext/190710523/CB_TX1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/CB_TX1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/ChipConfig.o: ../carte_moteur_Guerin_Herveleu.X/ChipConfig.c  .generated_files/flags/default/620ff6f72d34047bda7d0a034870f03d06ecea42 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/ChipConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/ChipConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/ChipConfig.c  -o ${OBJECTDIR}/_ext/190710523/ChipConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/ChipConfig.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/IO.o: ../carte_moteur_Guerin_Herveleu.X/IO.c  .generated_files/flags/default/b9cb2a1600c730d6e5b269164853c2dafa351431 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/IO.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/IO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/IO.c  -o ${OBJECTDIR}/_ext/190710523/IO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/IO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/PWM.o: ../carte_moteur_Guerin_Herveleu.X/PWM.c  .generated_files/flags/default/38f31239a516014f5d8bbc30e8424b97e67a9300 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/PWM.c  -o ${OBJECTDIR}/_ext/190710523/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/PWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/Robot.o: ../carte_moteur_Guerin_Herveleu.X/Robot.c  .generated_files/flags/default/2254d4221755204aa7b12c3a8a5a27ead02a25f1 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/Robot.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/Robot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/Robot.c  -o ${OBJECTDIR}/_ext/190710523/Robot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/Robot.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/ToolBox.o: ../carte_moteur_Guerin_Herveleu.X/ToolBox.c  .generated_files/flags/default/99c3fbcd93cb7f04db582a4e79df9fdc18272b1 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/ToolBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/ToolBox.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/ToolBox.c  -o ${OBJECTDIR}/_ext/190710523/ToolBox.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/ToolBox.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/UART.o: ../carte_moteur_Guerin_Herveleu.X/UART.c  .generated_files/flags/default/d8c2bffd5fd022409ca2164a08a52d36669a8921 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/UART.c  -o ${OBJECTDIR}/_ext/190710523/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/brouillonstrat.o: ../carte_moteur_Guerin_Herveleu.X/brouillonstrat.c  .generated_files/flags/default/7a15302c1df24ae2a1b6c9884f6641406195574 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/brouillonstrat.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/brouillonstrat.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/brouillonstrat.c  -o ${OBJECTDIR}/_ext/190710523/brouillonstrat.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/brouillonstrat.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/main.o: ../carte_moteur_Guerin_Herveleu.X/main.c  .generated_files/flags/default/c2cb491215d0b47721338f6c3019428a36b3b1de .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/main.c  -o ${OBJECTDIR}/_ext/190710523/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/timer.o: ../carte_moteur_Guerin_Herveleu.X/timer.c  .generated_files/flags/default/242f4847d8824feed44f0705d3460a82ef49f7af .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/timer.c  -o ${OBJECTDIR}/_ext/190710523/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/190710523/ADC.o: ../carte_moteur_Guerin_Herveleu.X/ADC.c  .generated_files/flags/default/822e7b6f5111615d66a026355e0c716bee615af4 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/ADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/ADC.c  -o ${OBJECTDIR}/_ext/190710523/ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/ADC.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/CB_RX1.o: ../carte_moteur_Guerin_Herveleu.X/CB_RX1.c  .generated_files/flags/default/317aff3f5f6b63f95f1aa0a4d7f8cb75c51c5de6 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_RX1.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_RX1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/CB_RX1.c  -o ${OBJECTDIR}/_ext/190710523/CB_RX1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/CB_RX1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/CB_TX1.o: ../carte_moteur_Guerin_Herveleu.X/CB_TX1.c  .generated_files/flags/default/19a685319d1c6f4478e283347eaffaeae9a6b0c6 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_TX1.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/CB_TX1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/CB_TX1.c  -o ${OBJECTDIR}/_ext/190710523/CB_TX1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/CB_TX1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/ChipConfig.o: ../carte_moteur_Guerin_Herveleu.X/ChipConfig.c  .generated_files/flags/default/dab27857439c7be75b986a4bdf03284db643ae6 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/ChipConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/ChipConfig.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/ChipConfig.c  -o ${OBJECTDIR}/_ext/190710523/ChipConfig.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/ChipConfig.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/IO.o: ../carte_moteur_Guerin_Herveleu.X/IO.c  .generated_files/flags/default/5d82f29979a991fb4c589f15759305451fa8c34e .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/IO.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/IO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/IO.c  -o ${OBJECTDIR}/_ext/190710523/IO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/IO.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/PWM.o: ../carte_moteur_Guerin_Herveleu.X/PWM.c  .generated_files/flags/default/dc1871d6c8e0a4718b9641bad4bc1f8c0affaeea .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/PWM.c  -o ${OBJECTDIR}/_ext/190710523/PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/PWM.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/Robot.o: ../carte_moteur_Guerin_Herveleu.X/Robot.c  .generated_files/flags/default/77b56276c33cdc6075737bf8590d9611129926c8 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/Robot.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/Robot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/Robot.c  -o ${OBJECTDIR}/_ext/190710523/Robot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/Robot.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/ToolBox.o: ../carte_moteur_Guerin_Herveleu.X/ToolBox.c  .generated_files/flags/default/47b3f1dc7fa8dab0ff05383723136d960ccbca8f .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/ToolBox.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/ToolBox.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/ToolBox.c  -o ${OBJECTDIR}/_ext/190710523/ToolBox.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/ToolBox.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/UART.o: ../carte_moteur_Guerin_Herveleu.X/UART.c  .generated_files/flags/default/161746891f0b1879d7c6f6a2fb28f3d552949898 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/UART.c  -o ${OBJECTDIR}/_ext/190710523/UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/UART.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/brouillonstrat.o: ../carte_moteur_Guerin_Herveleu.X/brouillonstrat.c  .generated_files/flags/default/ae36055572ff46ced4f6ea2a895be8d006c7b6a5 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/brouillonstrat.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/brouillonstrat.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/brouillonstrat.c  -o ${OBJECTDIR}/_ext/190710523/brouillonstrat.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/brouillonstrat.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/main.o: ../carte_moteur_Guerin_Herveleu.X/main.c  .generated_files/flags/default/4f4c4d28bc29faffbe803c772acc9962f3505aec .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/main.c  -o ${OBJECTDIR}/_ext/190710523/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/190710523/timer.o: ../carte_moteur_Guerin_Herveleu.X/timer.c  .generated_files/flags/default/74f79d468dbb227e652a8ccbece4a21f116a7d7 .generated_files/flags/default/54850bb106185342aa34b1544b5c9533308813ce
	@${MKDIR} "${OBJECTDIR}/_ext/190710523" 
	@${RM} ${OBJECTDIR}/_ext/190710523/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/190710523/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../carte_moteur_Guerin_Herveleu.X/timer.c  -o ${OBJECTDIR}/_ext/190710523/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/190710523/timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
