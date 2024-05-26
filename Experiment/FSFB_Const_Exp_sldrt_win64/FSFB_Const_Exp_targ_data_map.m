  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FSFB_Const_Exp_P)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_P.initialValues
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FSFB_Const_Exp_P.PacketInput_MaxMissedTicks
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 5;
	
	  ;% FSFB_Const_Exp_P.PacketOutput_MaxMissedTicks
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 6;
	
	  ;% FSFB_Const_Exp_P.PacketInput_YieldWhenWaiting
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 7;
	
	  ;% FSFB_Const_Exp_P.PacketOutput_YieldWhenWaiting
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_P.PacketInput_PacketID
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FSFB_Const_Exp_P.PacketOutput_PacketID
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_P.Gain_Gain
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FSFB_Const_Exp_P.Gain1_Gain
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FSFB_Const_Exp_P.filter1_A
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FSFB_Const_Exp_P.filter1_C
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 4;
	
	  ;% FSFB_Const_Exp_P.filter2_A
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 6;
	
	  ;% FSFB_Const_Exp_P.filter2_C
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 8;
	
	  ;% FSFB_Const_Exp_P.Constant_Value
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 10;
	
	  ;% FSFB_Const_Exp_P.Constant1_Value
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 11;
	
	  ;% FSFB_Const_Exp_P.Constant2_Value
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 12;
	
	  ;% FSFB_Const_Exp_P.Constant3_Value
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 13;
	
	  ;% FSFB_Const_Exp_P.Constant4_Value
	  section.data(11).logicalSrcIdx = 19;
	  section.data(11).dtTransOffset = 14;
	
	  ;% FSFB_Const_Exp_P.adaptivecontroller_P1_Size
	  section.data(12).logicalSrcIdx = 20;
	  section.data(12).dtTransOffset = 15;
	
	  ;% FSFB_Const_Exp_P.adaptivecontroller_P1
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 17;
	
	  ;% FSFB_Const_Exp_P.adaptivecontroller_P2_Size
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 19;
	
	  ;% FSFB_Const_Exp_P.adaptivecontroller_P2
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 21;
	
	  ;% FSFB_Const_Exp_P.adaptivecontroller_P3_Size
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 23;
	
	  ;% FSFB_Const_Exp_P.adaptivecontroller_P3
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 25;
	
	  ;% FSFB_Const_Exp_P.Gain_Gain_k
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 27;
	
	  ;% FSFB_Const_Exp_P.Gain2_Gain
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 28;
	
	  ;% FSFB_Const_Exp_P.Saturation_UpperSat
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 29;
	
	  ;% FSFB_Const_Exp_P.Saturation_LowerSat
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 30;
	
	  ;% FSFB_Const_Exp_P.RadToDeg_Gain
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 31;
	
	  ;% FSFB_Const_Exp_P.Constant_Value_k
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 32;
	
	  ;% FSFB_Const_Exp_P.Gain1_Gain_k
	  section.data(24).logicalSrcIdx = 32;
	  section.data(24).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FSFB_Const_Exp_B)
    ;%
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_B.Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FSFB_Const_Exp_B.Gain1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FSFB_Const_Exp_B.filter1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FSFB_Const_Exp_B.filter2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% FSFB_Const_Exp_B.Fcn
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% FSFB_Const_Exp_B.Fcn1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% FSFB_Const_Exp_B.Derivative
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% FSFB_Const_Exp_B.Derivative1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% FSFB_Const_Exp_B.Integrator
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% FSFB_Const_Exp_B.Constant
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% FSFB_Const_Exp_B.Constant1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% FSFB_Const_Exp_B.Constant2
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% FSFB_Const_Exp_B.Constant3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% FSFB_Const_Exp_B.Constant4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% FSFB_Const_Exp_B.adaptivecontroller_o1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% FSFB_Const_Exp_B.adaptivecontroller_o2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% FSFB_Const_Exp_B.adaptivecontroller_o3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 27;
	
	  ;% FSFB_Const_Exp_B.Saturation
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% FSFB_Const_Exp_B.e
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 31;
	
	  ;% FSFB_Const_Exp_B.RadToDeg
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 33;
	
	  ;% FSFB_Const_Exp_B.edot
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 35;
	
	  ;% FSFB_Const_Exp_B.qdot
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_B.Add
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_B.PacketInput
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (FSFB_Const_Exp_DW)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_DW.TimeStampA
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FSFB_Const_Exp_DW.LastUAtTimeA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FSFB_Const_Exp_DW.TimeStampB
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% FSFB_Const_Exp_DW.LastUAtTimeB
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% FSFB_Const_Exp_DW.TimeStampA_a
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% FSFB_Const_Exp_DW.LastUAtTimeA_c
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% FSFB_Const_Exp_DW.TimeStampB_i
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% FSFB_Const_Exp_DW.LastUAtTimeB_p
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% FSFB_Const_Exp_DW.TimeStampA_n
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% FSFB_Const_Exp_DW.LastUAtTimeA_e
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% FSFB_Const_Exp_DW.TimeStampB_c
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% FSFB_Const_Exp_DW.LastUAtTimeB_f
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% FSFB_Const_Exp_DW.PacketInput_PWORK
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% FSFB_Const_Exp_DW.ControlInput_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% FSFB_Const_Exp_DW.Error_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% FSFB_Const_Exp_DW.parameterupdates_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 4;
	
	  ;% FSFB_Const_Exp_DW.qd_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 5;
	
	  ;% FSFB_Const_Exp_DW.velocityError_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 6;
	
	  ;% FSFB_Const_Exp_DW.PacketOutput_PWORK
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4183878578;
  targMap.checksum1 = 499556337;
  targMap.checksum2 = 3930033813;
  targMap.checksum3 = 2389889923;

