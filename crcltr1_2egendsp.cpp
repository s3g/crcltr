#include "crcltr1_2egendsp.h"

namespace crcltr1_2egendsp {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Change __m_change_96;
	Change __m_change_126;
	DCBlock __m_dcblock_87;
	DCBlock __m_dcblock_80;
	DCBlock __m_dcblock_84;
	DCBlock __m_dcblock_82;
	DCBlock __m_dcblock_200;
	DCBlock __m_dcblock_193;
	Data m_lplp_60;
	Data m_vplp_58;
	Delay m_delay_32;
	Delay m_delay_27;
	Delta __m_delta_74;
	Delta __m_delta_78;
	Delta __m_delta_94;
	Delta __m_delta_95;
	Delta __m_delta_97;
	Delta __m_delta_124;
	Delta __m_delta_76;
	Delta __m_delta_103;
	Delta __m_delta_75;
	Phasor __m_phasor_102;
	Phasor __m_phasor_127;
	PlusEquals __m_pluseq_125;
	PlusEquals __m_pluseq_98;
	Rate __m_rate_156;
	SineCycle __m_cycle_157;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_increment_14;
	t_sample m_history_25;
	t_sample m_remain_15;
	t_sample m_current_16;
	t_sample m_target_13;
	t_sample m_remain_11;
	t_sample m_current_12;
	t_sample m_target_17;
	t_sample __m_latch_79;
	t_sample m_history_18;
	t_sample m_history_21;
	t_sample __m_carry_72;
	t_sample m_increment_10;
	t_sample m_history_20;
	t_sample __m_latch_77;
	t_sample m_history_19;
	t_sample m_history_9;
	t_sample __m_latch_99;
	t_sample __m_latch_100;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_history_2;
	t_sample __m_slide_187;
	t_sample __m_slide_194;
	t_sample __m_slide_190;
	t_sample __m_count_70;
	t_sample m_history_3;
	t_sample m_history_5;
	t_sample samples_to_seconds;
	t_sample __m_latch_101;
	t_sample m_history_4;
	t_sample m_history_8;
	t_sample m_history_6;
	t_sample m_p_7;
	t_sample m_history_26;
	t_sample __m_carry_68;
	t_sample m_history_22;
	t_sample m_history_38;
	t_sample m_history_37;
	t_sample m_target_36;
	t_sample m_history_39;
	t_sample m_remain_41;
	t_sample m_increment_40;
	t_sample m_current_42;
	t_sample m_current_35;
	t_sample m_increment_33;
	t_sample m_remain_29;
	t_sample m_increment_28;
	t_sample m_remain_34;
	t_sample m_current_30;
	t_sample m_history_24;
	t_sample m_target_31;
	t_sample __m_count_66;
	t_sample m_target_43;
	t_sample m_remain_45;
	t_sample m_ctrl_56;
	t_sample m_ctrl_55;
	t_sample m_ctrl_54;
	t_sample m_sw_57;
	t_sample m_ctrl_59;
	t_sample m_history_23;
	t_sample m_increment_44;
	t_sample m_sw_53;
	t_sample m_ctrl_51;
	t_sample m_target_47;
	t_sample m_current_46;
	t_sample m_gate_52;
	t_sample __m_slide_197;
	t_sample m_ctrl_50;
	t_sample m_button_49;
	t_sample m_ctrl_48;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_p_7 = ((int)1);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_increment_10 = ((int)0);
		m_remain_11 = ((int)0);
		m_current_12 = ((int)0);
		m_target_13 = ((int)0);
		m_increment_14 = ((int)0);
		m_remain_15 = ((int)0);
		m_current_16 = ((int)0);
		m_target_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_history_24 = ((int)0);
		m_history_25 = ((int)0);
		m_history_26 = ((int)0);
		m_delay_27.reset("m_delay_27", samplerate);
		m_increment_28 = ((int)0);
		m_remain_29 = ((int)0);
		m_current_30 = ((int)0);
		m_target_31 = ((int)0);
		m_delay_32.reset("m_delay_32", samplerate);
		m_increment_33 = ((int)0);
		m_remain_34 = ((int)0);
		m_current_35 = ((int)0);
		m_target_36 = ((int)0);
		m_history_37 = ((int)0);
		m_history_38 = ((int)0);
		m_history_39 = ((int)0);
		m_increment_40 = ((int)0);
		m_remain_41 = ((int)0);
		m_current_42 = ((int)0);
		m_target_43 = ((int)0);
		m_increment_44 = ((int)0);
		m_remain_45 = ((int)0);
		m_current_46 = ((int)0);
		m_target_47 = ((int)0);
		m_ctrl_48 = 0;
		m_button_49 = 0;
		m_ctrl_50 = 1;
		m_ctrl_51 = 0;
		m_gate_52 = 0;
		m_sw_53 = 0.5;
		m_ctrl_54 = 0.5;
		m_ctrl_55 = 0;
		m_ctrl_56 = 1;
		m_sw_57 = 0.5;
		m_vplp_58.reset("vplp", (samplerate * 32), ((int)2));
		m_ctrl_59 = 1;
		m_lplp_60.reset("lplp", (samplerate * 32), ((int)2));
		__m_count_66 = 0;
		__m_carry_68 = 0;
		__m_count_70 = 0;
		__m_carry_72 = 0;
		__m_delta_74.reset(0);
		__m_delta_75.reset(0);
		__m_delta_76.reset(0);
		__m_latch_77 = 0;
		__m_delta_78.reset(0);
		__m_latch_79 = 0;
		__m_dcblock_80.reset();
		__m_dcblock_82.reset();
		__m_dcblock_84.reset();
		__m_dcblock_87.reset();
		__m_delta_94.reset(0);
		__m_delta_95.reset(0);
		__m_change_96.reset(0);
		__m_delta_97.reset(0);
		__m_pluseq_98.reset(0);
		__m_latch_99 = 1;
		__m_latch_100 = 0;
		__m_latch_101 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_102.reset(0);
		__m_delta_103.reset(2);
		__m_delta_124.reset(0);
		__m_pluseq_125.reset(0);
		__m_change_126.reset(0);
		__m_phasor_127.reset(0);
		__m_rate_156.reset();
		__m_cycle_157.reset(samplerate, 0);
		__m_slide_187 = 0;
		__m_slide_190 = 0;
		__m_dcblock_193.reset();
		__m_slide_194 = 0;
		__m_slide_197 = 0;
		__m_dcblock_200.reset();
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int lplp_dim = m_lplp_60.dim;
		int lplp_channels = m_lplp_60.channels;
		int lplp_dim_4140 = lplp_dim;
		int vplp_dim = m_vplp_58.dim;
		int vplp_channels = m_vplp_58.channels;
		int vplp_dim_4071 = vplp_dim;
		int or_4052 = (m_gate_52 || m_button_49);
		t_sample mul_4074 = (m_sw_53 * ((int)2));
		t_sample add_4073 = (mul_4074 + ((int)1));
		t_sample choice_61 = int(add_4073);
		t_sample gate_4075 = (((choice_61 >= 1) && (choice_61 < 2)) ? or_4052 : 0);
		t_sample gate_4076 = (((choice_61 >= 2) && (choice_61 < 3)) ? or_4052 : 0);
		t_sample gate_4077 = ((choice_61 >= 3) ? or_4052 : 0);
		t_sample gen_10683 = gate_4077;
		t_sample gen_10682 = gate_4075;
		t_sample gen_10681 = gate_4076;
		t_sample cond_62 = (gen_10682 + gen_10683);
		int switch_3997 = (cond_62 ? ((int)-1) : ((int)0));
		t_sample cond_63 = (gen_10681 + gen_10682);
		int switch_4083 = (cond_63 ? ((int)-1) : ((int)0));
		t_sample mul_18361 = (m_sw_57 * ((int)2));
		t_sample add_18360 = (mul_18361 + ((int)1));
		t_sample choice_64 = int(add_18360);
		t_sample selector_20638 = ((choice_64 >= 3) ? ((int)1) : ((choice_64 >= 2) ? ((int)0) : ((choice_64 >= 1) ? ((int)0) : 0)));
		t_sample choice_65 = int(add_18360);
		t_sample selector_16628 = ((choice_65 >= 3) ? ((int)0) : ((choice_65 >= 2) ? ((int)1) : ((choice_65 >= 1) ? ((int)0) : 0)));
		int or_4091 = (gen_10681 || gen_10682);
		int prelatch_3810 = or_4091;
		int not_4110 = (!or_4091);
		int or_4054 = (gen_10682 || gen_10683);
		int not_4061 = (!or_4054);
		int prelatch_3904 = or_4054;
		int prelatch_3803 = prelatch_3904;
		int prelatch_3906 = prelatch_3810;
		t_sample mstosamps_4103 = (((int)12) * (samplerate * 0.001));
		t_sample mstosamps_4045 = (((int)12) * (samplerate * 0.001));
		bool chan_ignore_85 = ((((int)1) < 0) || (((int)1) >= lplp_channels));
		bool chan_ignore_88 = ((((int)1) < 0) || (((int)1) >= vplp_channels));
		t_sample mul_4022 = (m_sw_57 * ((int)2));
		t_sample add_4021 = (mul_4022 + ((int)1));
		t_sample choice_90 = int(add_4021);
		t_sample mul_4034 = (m_sw_57 * ((int)2));
		t_sample add_4033 = (mul_4034 + ((int)1));
		t_sample choice_91 = int(add_4033);
		t_sample mul_4026 = (m_sw_57 * ((int)2));
		t_sample add_4025 = (mul_4026 + ((int)1));
		t_sample choice_92 = int(add_4025);
		t_sample mul_4030 = (m_sw_57 * ((int)2));
		t_sample add_4029 = (mul_4030 + ((int)1));
		t_sample choice_93 = int(add_4029);
		int prelatch_3905 = prelatch_3810;
		int prelatch_3903 = prelatch_3904;
		int dim_3883 = vplp_dim;
		samples_to_seconds = (1 / samplerate);
		bool chan_ignore_118 = ((1 < 0) || (1 >= vplp_channels));
		int chan_clamp_150 = clamp(1, 0, (lplp_channels - 1));
		int chan_clamp_181 = clamp(1, 0, (lplp_channels - 1));
		t_sample iup_188 = (1 / maximum(1, abs(((int)100))));
		t_sample idown_189 = (1 / maximum(1, abs(((int)100))));
		t_sample iup_191 = (1 / maximum(1, abs(((int)100))));
		t_sample idown_192 = (1 / maximum(1, abs(((int)100))));
		t_sample iup_195 = (1 / maximum(1, abs(((int)100))));
		t_sample idown_196 = (1 / maximum(1, abs(((int)100))));
		t_sample iup_198 = (1 / maximum(1, abs(((int)100))));
		t_sample idown_199 = (1 / maximum(1, abs(((int)100))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out4 = switch_3997;
			t_sample out3 = switch_4083;
			t_sample out6 = selector_20638;
			t_sample out5 = selector_16628;
			__m_count_66 = (not_4110 ? 0 : (fixdenorm(__m_count_66 + ((int)1))));
			int carry_67 = 0;
			if ((not_4110 != 0)) {
				__m_count_66 = 0;
				__m_carry_68 = 0;
				
			} else if (((lplp_dim_4140 > 0) && (__m_count_66 >= lplp_dim_4140))) {
				int wraps_69 = (__m_count_66 / lplp_dim_4140);
				__m_carry_68 = (__m_carry_68 + wraps_69);
				__m_count_66 = (__m_count_66 - (wraps_69 * lplp_dim_4140));
				carry_67 = 1;
				
			};
			int counter_4114 = __m_count_66;
			int counter_4115 = carry_67;
			int counter_4116 = __m_carry_68;
			__m_count_70 = (not_4061 ? 0 : (fixdenorm(__m_count_70 + ((int)1))));
			int carry_71 = 0;
			if ((not_4061 != 0)) {
				__m_count_70 = 0;
				__m_carry_72 = 0;
				
			} else if (((vplp_dim_4071 > 0) && (__m_count_70 >= vplp_dim_4071))) {
				int wraps_73 = (__m_count_70 / vplp_dim_4071);
				__m_carry_72 = (__m_carry_72 + wraps_73);
				__m_count_70 = (__m_count_70 - (wraps_73 * vplp_dim_4071));
				carry_71 = 1;
				
			};
			int counter_4065 = __m_count_70;
			int counter_4066 = carry_71;
			int counter_4067 = __m_carry_72;
			if ((__m_delta_74(prelatch_3810) != ((int)0))) {
				m_target_47 = prelatch_3810;
				m_remain_45 = (((int)10) * (samplerate * 0.001));
				m_increment_44 = safediv((m_target_47 - m_current_46), m_remain_45);
				
			};
			if ((m_remain_45 > ((int)0))) {
				m_current_46 = (m_target_47 - (m_increment_44 * m_remain_45));
				m_remain_45 = (m_remain_45 - ((int)1));
				
			} else {
				m_current_46 = m_target_47;
				
			};
			t_sample expr_3807 = m_current_46;
			if ((__m_delta_75(prelatch_3803) != ((int)0))) {
				m_target_43 = prelatch_3803;
				m_remain_41 = (((int)10) * (samplerate * 0.001));
				m_increment_40 = safediv((m_target_43 - m_current_42), m_remain_41);
				
			};
			if ((m_remain_41 > ((int)0))) {
				m_current_42 = (m_target_43 - (m_increment_40 * m_remain_41));
				m_remain_41 = (m_remain_41 - ((int)1));
				
			} else {
				m_current_42 = m_target_43;
				
			};
			t_sample expr_3800 = m_current_42;
			t_sample mix_22597 = (m_history_39 + (((t_sample)0.003926980723806) * (m_ctrl_50 - m_history_39)));
			t_sample mix_3962 = mix_22597;
			t_sample mix_22598 = (m_history_38 + (((t_sample)0.003926980723806) * (mix_3962 - m_history_38)));
			t_sample mix_3960 = mix_22598;
			t_sample mix_22599 = (m_history_37 + (((t_sample)0.003926980723806) * (mix_3960 - m_history_37)));
			t_sample mix_3958 = mix_22599;
			t_sample gen_4088 = mix_3958;
			t_sample history_3963_next_3965 = fixdenorm(mix_3962);
			t_sample history_3961_next_3966 = fixdenorm(mix_3960);
			t_sample history_3959_next_3967 = fixdenorm(mix_3958);
			if ((__m_delta_76(prelatch_3906) != ((int)0))) {
				m_target_36 = prelatch_3906;
				m_remain_34 = (((int)10) * (samplerate * 0.001));
				m_increment_33 = safediv((m_target_36 - m_current_35), m_remain_34);
				
			};
			if ((m_remain_34 > ((int)0))) {
				m_current_35 = (m_target_36 - (m_increment_33 * m_remain_34));
				m_remain_34 = (m_remain_34 - ((int)1));
				
			} else {
				m_current_35 = m_target_36;
				
			};
			t_sample expr_4525 = m_current_35;
			t_sample tap_4102 = m_delay_32.read_linear(mstosamps_4103);
			t_sample gen_4528 = tap_4102;
			t_sample switch_3811 = (prelatch_3810 ? expr_4525 : expr_3807);
			t_sample latch_3920 = gen_4528;
			__m_latch_77 = ((latch_3920 != 0) ? or_4091 : __m_latch_77);
			t_sample latch_4094 = __m_latch_77;
			int switch_4113 = (latch_4094 ? counter_4114 : ((int)-1));
			if ((__m_delta_78(prelatch_3904) != ((int)0))) {
				m_target_31 = prelatch_3904;
				m_remain_29 = (((int)10) * (samplerate * 0.001));
				m_increment_28 = safediv((m_target_31 - m_current_30), m_remain_29);
				
			};
			if ((m_remain_29 > ((int)0))) {
				m_current_30 = (m_target_31 - (m_increment_28 * m_remain_29));
				m_remain_29 = (m_remain_29 - ((int)1));
				
			} else {
				m_current_30 = m_target_31;
				
			};
			t_sample expr_4047 = m_current_30;
			t_sample tap_4044 = m_delay_27.read_linear(mstosamps_4045);
			t_sample gen_4049 = tap_4044;
			t_sample switch_3804 = (prelatch_3803 ? expr_4047 : expr_3800);
			t_sample latch_3919 = gen_4049;
			__m_latch_79 = ((latch_3919 != 0) ? or_4054 : __m_latch_79);
			t_sample latch_4060 = __m_latch_79;
			int switch_4064 = (latch_4060 ? counter_4065 : ((int)-1));
			t_sample mix_22600 = (m_history_26 + (((t_sample)0.003926980723806) * (m_ctrl_54 - m_history_26)));
			t_sample mix_21790 = mix_22600;
			t_sample mix_22601 = (m_history_25 + (((t_sample)0.003926980723806) * (mix_21790 - m_history_25)));
			t_sample mix_21796 = mix_22601;
			t_sample mix_22602 = (m_history_24 + (((t_sample)0.003926980723806) * (mix_21796 - m_history_24)));
			t_sample mix_21795 = mix_22602;
			t_sample gen_4090 = mix_21795;
			t_sample history_3963_next_21797 = fixdenorm(mix_21790);
			t_sample history_3961_next_21794 = fixdenorm(mix_21796);
			t_sample history_3959_next_21793 = fixdenorm(mix_21795);
			t_sample mul_3988 = (in1 * m_ctrl_48);
			t_sample mul_3994 = (mul_3988 * ((t_sample)0.5));
			t_sample tanh_3993 = tanh(mul_3994);
			t_sample mul_3992 = (tanh_3993 * ((int)2));
			t_sample mul_3828 = (mul_3992 * switch_3811);
			t_sample dcblock_4118 = __m_dcblock_80(mul_3828);
			bool index_ignore_81 = ((switch_4113 >= lplp_dim) || (switch_4113 < 0));
			if ((!index_ignore_81)) {
				m_lplp_60.write(dcblock_4118, switch_4113, 0);
				
			};
			t_sample mul_3826 = (mul_3992 * switch_3804);
			t_sample dcblock_3922 = __m_dcblock_82(mul_3826);
			bool index_ignore_83 = ((switch_4064 >= vplp_dim) || (switch_4064 < 0));
			if ((!index_ignore_83)) {
				m_vplp_58.write(dcblock_3922, switch_4064, 0);
				
			};
			t_sample mul_3987 = (in2 * m_ctrl_48);
			t_sample mul_3991 = (mul_3987 * ((t_sample)0.5));
			t_sample tanh_3990 = tanh(mul_3991);
			t_sample mul_3989 = (tanh_3990 * ((int)2));
			t_sample mul_3827 = (mul_3989 * switch_3811);
			t_sample dcblock_4117 = __m_dcblock_84(mul_3827);
			bool index_ignore_86 = ((switch_4113 >= lplp_dim) || (switch_4113 < 0));
			if ((!(chan_ignore_85 || index_ignore_86))) {
				m_lplp_60.write(dcblock_4117, switch_4113, ((int)1));
				
			};
			t_sample mul_3825 = (mul_3989 * switch_3804);
			t_sample dcblock_3921 = __m_dcblock_87(mul_3825);
			bool index_ignore_89 = ((switch_4064 >= vplp_dim) || (switch_4064 < 0));
			if ((!(chan_ignore_88 || index_ignore_89))) {
				m_vplp_58.write(dcblock_3921, switch_4064, ((int)1));
				
			};
			t_sample selector_4023 = ((choice_90 >= 3) ? in2 : ((choice_90 >= 2) ? in2 : ((choice_90 >= 1) ? ((int)0) : 0)));
			t_sample selector_4035 = ((choice_91 >= 3) ? in1 : ((choice_91 >= 2) ? in1 : ((choice_91 >= 1) ? ((int)0) : 0)));
			t_sample mix_22603 = (m_history_23 + (((t_sample)0.003926980723806) * (m_ctrl_59 - m_history_23)));
			t_sample mix_21802 = mix_22603;
			t_sample mix_22604 = (m_history_22 + (((t_sample)0.003926980723806) * (mix_21802 - m_history_22)));
			t_sample mix_21804 = mix_22604;
			t_sample mix_22605 = (m_history_21 + (((t_sample)0.003926980723806) * (mix_21804 - m_history_21)));
			t_sample mix_21803 = mix_22605;
			t_sample gen_4053 = mix_21803;
			t_sample history_3963_next_21810 = fixdenorm(mix_21802);
			t_sample history_3961_next_21808 = fixdenorm(mix_21804);
			t_sample history_3959_next_21805 = fixdenorm(mix_21803);
			t_sample selector_4027 = ((choice_92 >= 3) ? in1 : ((choice_92 >= 2) ? in1 : ((choice_92 >= 1) ? ((int)0) : 0)));
			t_sample mix_22606 = (m_history_20 + (((t_sample)0.003926980723806) * (m_ctrl_55 - m_history_20)));
			t_sample mix_21815 = mix_22606;
			t_sample mix_22607 = (m_history_19 + (((t_sample)0.003926980723806) * (mix_21815 - m_history_19)));
			t_sample mix_21817 = mix_22607;
			t_sample mix_22608 = (m_history_18 + (((t_sample)0.003926980723806) * (mix_21817 - m_history_18)));
			t_sample mix_21816 = mix_22608;
			t_sample gen_4084 = mix_21816;
			t_sample history_3963_next_21821 = fixdenorm(mix_21815);
			t_sample history_3961_next_21823 = fixdenorm(mix_21817);
			t_sample history_3959_next_21822 = fixdenorm(mix_21816);
			t_sample selector_4031 = ((choice_93 >= 3) ? in2 : ((choice_93 >= 2) ? in2 : ((choice_93 >= 1) ? ((int)0) : 0)));
			if ((__m_delta_94(prelatch_3905) != ((int)0))) {
				m_target_17 = prelatch_3905;
				m_remain_15 = (((int)10) * (samplerate * 0.001));
				m_increment_14 = safediv((m_target_17 - m_current_16), m_remain_15);
				
			};
			if ((m_remain_15 > ((int)0))) {
				m_current_16 = (m_target_17 - (m_increment_14 * m_remain_15));
				m_remain_15 = (m_remain_15 - ((int)1));
				
			} else {
				m_current_16 = m_target_17;
				
			};
			t_sample expr_4098 = m_current_16;
			if ((__m_delta_95(prelatch_3903) != ((int)0))) {
				m_target_13 = prelatch_3903;
				m_remain_11 = (((int)10) * (samplerate * 0.001));
				m_increment_10 = safediv((m_target_13 - m_current_12), m_remain_11);
				
			};
			if ((m_remain_11 > ((int)0))) {
				m_current_12 = (m_target_13 - (m_increment_10 * m_remain_11));
				m_remain_11 = (m_remain_11 - ((int)1));
				
			} else {
				m_current_12 = m_target_13;
				
			};
			t_sample expr_4040 = m_current_12;
			t_sample rsub_4055 = (((int)1) - latch_4060);
			int int_4056 = int(rsub_4055);
			int change_4057 = __m_change_96(int_4056);
			int eqp_4058 = ((int_4056 == change_4057) ? int_4056 : 0);
			int gen_4059 = eqp_4058;
			t_sample mix_22609 = (m_history_9 + (((t_sample)0.001308996565174) * (m_ctrl_51 - m_history_9)));
			t_sample mix_3975 = mix_22609;
			t_sample mix_22610 = (m_history_8 + (((t_sample)0.001308996565174) * (mix_3975 - m_history_8)));
			t_sample mix_3973 = mix_22610;
			t_sample gen_3980 = mix_3973;
			t_sample history_3976_next_3978 = fixdenorm(mix_3975);
			t_sample history_3974_next_3979 = fixdenorm(mix_3973);
			t_sample floor_3981 = floor(gen_3980);
			t_sample add_3982 = (floor_3981 + ((int)1));
			t_sample delta_4069 = __m_delta_97(latch_4060);
			int gt_4068 = (delta_4069 > ((int)0));
			t_sample plusequals_4070 = __m_pluseq_98.post(latch_4060, gt_4068, 0);
			t_sample chunksiz_3829 = plusequals_4070;
			t_sample mul_3872 = (gen_4053 * samplerate);
			__m_latch_99 = ((m_p_7 != 0) ? ((int)48000) : __m_latch_99);
			t_sample latch_3864 = __m_latch_99;
			__m_latch_100 = ((m_p_7 != 0) ? ((int)0) : __m_latch_100);
			t_sample latch_3866 = __m_latch_100;
			t_sample sub_3862 = (chunksiz_3829 - ((int)480));
			__m_latch_101 = ((m_p_7 != 0) ? sub_3862 : __m_latch_101);
			t_sample latch_3865 = __m_latch_101;
			t_sample div_3886 = safediv(latch_3865, latch_3864);
			t_sample add_3884 = (latch_3866 + latch_3865);
			t_sample max_3880 = ((latch_3866 < add_3884) ? add_3884 : latch_3866);
			t_sample clamp_3882 = ((max_3880 <= ((int)4)) ? ((int)4) : ((max_3880 >= dim_3883) ? dim_3883 : max_3880));
			t_sample min_3879 = ((add_3884 < latch_3866) ? add_3884 : latch_3866);
			t_sample clamp_3881 = ((min_3879 <= ((int)0)) ? ((int)0) : ((min_3879 >= dim_3883) ? dim_3883 : min_3879));
			t_sample sub_3878 = (clamp_3882 - clamp_3881);
			t_sample div_3871 = safediv(mul_3872, sub_3878);
			if ((gen_4059 != 0)) {
				__m_phasor_102.phase = 0;
				
			};
			t_sample phasor_3873 = __m_phasor_102(div_3871, samples_to_seconds);
			t_sample delta_3869 = __m_delta_103(phasor_3873);
			t_sample abs_3868 = fabs(delta_3869);
			int gt_3867 = (abs_3868 > ((t_sample)0.25));
			t_sample triangle_3885 = triangle(phasor_3873, ((t_sample)0.5));
			t_sample mul_3887 = (triangle_3885 * div_3886);
			t_sample clamp_3888 = ((mul_3887 <= ((int)0)) ? ((int)0) : ((mul_3887 >= ((int)1)) ? ((int)1) : mul_3887));
			t_sample mul_3870 = (phasor_3873 * sub_3878);
			t_sample add_3874 = (mul_3870 + clamp_3881);
			int index_trunc_104 = fixnan(floor(add_3874));
			double index_fract_105 = (add_3874 - index_trunc_104);
			int index_trunc_106 = (index_trunc_104 - 1);
			int index_trunc_107 = (index_trunc_104 + 1);
			int index_trunc_108 = (index_trunc_104 + 2);
			bool index_ignore_109 = ((index_trunc_106 >= vplp_dim) || (index_trunc_106 < 0));
			bool index_ignore_110 = ((index_trunc_104 >= vplp_dim) || (index_trunc_104 < 0));
			bool index_ignore_111 = ((index_trunc_107 >= vplp_dim) || (index_trunc_107 < 0));
			bool index_ignore_112 = ((index_trunc_108 >= vplp_dim) || (index_trunc_108 < 0));
			// samples vplp channel 1;
			double read_vplp_113 = (index_ignore_109 ? 0 : m_vplp_58.read(index_trunc_106, 0));
			double read_vplp_114 = (index_ignore_110 ? 0 : m_vplp_58.read(index_trunc_104, 0));
			double read_vplp_115 = (index_ignore_111 ? 0 : m_vplp_58.read(index_trunc_107, 0));
			double read_vplp_116 = (index_ignore_112 ? 0 : m_vplp_58.read(index_trunc_108, 0));
			double readinterp_117 = spline_interp(index_fract_105, read_vplp_113, read_vplp_114, read_vplp_115, read_vplp_116);
			// samples vplp channel 2;
			double read_vplp_119 = ((chan_ignore_118 || index_ignore_109) ? 0 : m_vplp_58.read(index_trunc_106, 1));
			double read_vplp_120 = ((chan_ignore_118 || index_ignore_110) ? 0 : m_vplp_58.read(index_trunc_104, 1));
			double read_vplp_121 = ((chan_ignore_118 || index_ignore_111) ? 0 : m_vplp_58.read(index_trunc_107, 1));
			double read_vplp_122 = ((chan_ignore_118 || index_ignore_112) ? 0 : m_vplp_58.read(index_trunc_108, 1));
			double readinterp_123 = spline_interp(index_fract_105, read_vplp_119, read_vplp_120, read_vplp_121, read_vplp_122);
			t_sample sample_vplp_3875 = readinterp_117;
			t_sample sample_vplp_3876 = readinterp_123;
			t_sample index_vplp_3877 = add_3874;
			t_sample mul_3890 = (sample_vplp_3875 * clamp_3888);
			t_sample mul_3889 = (sample_vplp_3876 * clamp_3888);
			t_sample p_next_3893 = fixdenorm(gt_3867);
			t_sample mix_22611 = (mul_3890 + (expr_4047 * (selector_4027 - mul_3890)));
			t_sample mix_22612 = (mul_3889 + (expr_4040 * (selector_4023 - mul_3889)));
			t_sample delta_4126 = __m_delta_124(latch_4094);
			int gt_4125 = (delta_4126 > ((int)0));
			t_sample plusequals_4127 = __m_pluseq_125.post(latch_4094, gt_4125, 0);
			t_sample chunksiz_3955 = plusequals_4127;
			t_sample mul_3813 = (gen_4084 * ((int)2));
			t_sample rsub_3814 = (((int)2) - mul_3813);
			t_sample add_3812 = (rsub_3814 + ((t_sample)0.25));
			t_sample mix_22613 = (m_history_6 + (((t_sample)0.003926980723806) * (m_ctrl_56 - m_history_6)));
			t_sample mix_21844 = mix_22613;
			t_sample mix_22614 = (m_history_5 + (((t_sample)0.003926980723806) * (mix_21844 - m_history_5)));
			t_sample mix_21845 = mix_22614;
			t_sample mix_22615 = (m_history_4 + (((t_sample)0.003926980723806) * (mix_21845 - m_history_4)));
			t_sample mix_21850 = mix_22615;
			t_sample gen_4089 = mix_21850;
			t_sample history_3963_next_21849 = fixdenorm(mix_21844);
			t_sample history_3961_next_21848 = fixdenorm(mix_21845);
			t_sample history_3959_next_21851 = fixdenorm(mix_21850);
			t_sample rsub_4092 = (((int)1) - latch_4094);
			int int_21859 = int(rsub_4092);
			int change_21858 = __m_change_126(int_21859);
			int eqp_21857 = ((int_21859 == change_21858) ? int_21859 : 0);
			int gen_4093 = eqp_21857;
			t_sample rdiv_4139 = safediv(samplerate, plusequals_4127);
			t_sample mul_3953 = (rdiv_4139 * gen_4089);
			if ((gen_4093 != 0)) {
				__m_phasor_127.phase = 0;
				
			};
			t_sample phasor_4138 = __m_phasor_127(mul_3953, samples_to_seconds);
			t_sample phas_3948 = phasor_4138;
			t_sample phas_3902 = phas_3948;
			int wave_end_128 = ((lplp_dim > int(chunksiz_3955)) ? int(chunksiz_3955) : lplp_dim);
			int wave_offset_129;
			int wave_len_130;
			if ((wave_end_128 > 0)) {
				wave_offset_129 = 0;
				wave_len_130 = (wave_end_128 - 0);
				
			} else {
				wave_offset_129 = 0;
				wave_len_130 = lplp_dim;
				
			};
			double sample_index_131 = (phas_3902 * wave_len_130);
			int index_trunc_132 = fixnan(floor(sample_index_131));
			double index_fract_133 = (sample_index_131 - index_trunc_132);
			int index_trunc_134 = (index_trunc_132 - 1);
			int index_trunc_135 = (index_trunc_132 + 1);
			int index_trunc_136 = (index_trunc_132 + 2);
			int index_wrap_137 = ((index_trunc_134 < 0) ? ((wave_len_130 - 1) + ((index_trunc_134 + 1) % wave_len_130)) : (index_trunc_134 % wave_len_130));
			int index_offset_138 = (index_wrap_137 + wave_offset_129);
			int index_wrap_139 = ((index_trunc_132 < 0) ? ((wave_len_130 - 1) + ((index_trunc_132 + 1) % wave_len_130)) : (index_trunc_132 % wave_len_130));
			int index_offset_140 = (index_wrap_139 + wave_offset_129);
			int index_wrap_141 = ((index_trunc_135 < 0) ? ((wave_len_130 - 1) + ((index_trunc_135 + 1) % wave_len_130)) : (index_trunc_135 % wave_len_130));
			int index_offset_142 = (index_wrap_141 + wave_offset_129);
			int index_wrap_143 = ((index_trunc_136 < 0) ? ((wave_len_130 - 1) + ((index_trunc_136 + 1) % wave_len_130)) : (index_trunc_136 % wave_len_130));
			int index_offset_144 = (index_wrap_143 + wave_offset_129);
			// wave lplp channel 1;
			double read_lplp_145 = m_lplp_60.read(index_offset_138, 0);
			double read_lplp_146 = m_lplp_60.read(index_offset_140, 0);
			double read_lplp_147 = m_lplp_60.read(index_offset_142, 0);
			double read_lplp_148 = m_lplp_60.read(index_offset_144, 0);
			double readinterp_149 = spline_interp(index_fract_133, read_lplp_145, read_lplp_146, read_lplp_147, read_lplp_148);
			// wave lplp channel 2;
			double read_lplp_151 = m_lplp_60.read(index_offset_138, chan_clamp_150);
			double read_lplp_152 = m_lplp_60.read(index_offset_140, chan_clamp_150);
			double read_lplp_153 = m_lplp_60.read(index_offset_142, chan_clamp_150);
			double read_lplp_154 = m_lplp_60.read(index_offset_144, chan_clamp_150);
			double readinterp_155 = spline_interp(index_fract_133, read_lplp_151, read_lplp_152, read_lplp_153, read_lplp_154);
			t_sample sample_lplp_4134 = readinterp_149;
			t_sample sample_lplp_4135 = readinterp_155;
			t_sample index_lplp_4136 = sample_index_131;
			t_sample triangle_3899 = triangle(phas_3948, ((t_sample)0.5));
			t_sample sub_3942 = (triangle_3899 - ((t_sample)0.5));
			int gt_3936 = (sub_3942 > ((int)0));
			t_sample mul_3941 = (sub_3942 * ((int)2));
			t_sample add_3940 = (mul_3941 + ((t_sample)0.5));
			t_sample clamp_3937 = ((add_3940 <= ((int)0)) ? ((int)0) : ((add_3940 >= ((int)1)) ? ((int)1) : add_3940));
			t_sample switch_3939 = (((int)0) ? gt_3936 : clamp_3937);
			t_sample mul_4133 = (sample_lplp_4134 * switch_3939);
			t_sample mul_4123 = (sample_lplp_4135 * switch_3939);
			t_sample phas_3816 = phas_3948;
			t_sample rate_3815 = __m_rate_156.perform_off(phas_3816, add_3812);
			__m_cycle_157.phase(rate_3815);
			t_sample cycle_3985 = __m_cycle_157(__sinedata);
			t_sample cycleindex_3986 = __m_cycle_157.phase();
			t_sample sub_22623 = (cycle_3985 - (-1));
			t_sample scale_22620 = ((safepow((sub_22623 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample scale_3984 = scale_22620;
			t_sample triangle_3971 = triangle(rate_3815, ((t_sample)0.5));
			t_sample sub_21863 = (triangle_3971 - ((t_sample)0.5));
			int gt_21866 = (sub_21863 > ((int)0));
			t_sample mul_21865 = (sub_21863 * ((int)2));
			t_sample add_21870 = (mul_21865 + ((t_sample)0.5));
			t_sample clamp_21869 = ((add_21870 <= ((int)0)) ? ((int)0) : ((add_21870 >= ((int)1)) ? ((int)1) : add_21870));
			t_sample switch_21864 = (((int)0) ? gt_21866 : clamp_21869);
			t_sample gen_3972 = switch_21864;
			t_sample choice_158 = int(add_3982);
			t_sample selector_3983 = ((choice_158 >= 3) ? gen_3972 : ((choice_158 >= 2) ? scale_3984 : ((choice_158 >= 1) ? gen_4084 : 0)));
			t_sample mix_22628 = (m_history_3 + (((t_sample)0.003926980723806) * (selector_3983 - m_history_3)));
			t_sample mix_21871 = mix_22628;
			t_sample mix_22629 = (m_history_2 + (((t_sample)0.003926980723806) * (mix_21871 - m_history_2)));
			t_sample mix_21872 = mix_22629;
			t_sample mix_22630 = (m_history_1 + (((t_sample)0.003926980723806) * (mix_21872 - m_history_1)));
			t_sample mix_21878 = mix_22630;
			t_sample gen_3968 = mix_21878;
			t_sample history_3963_next_21877 = fixdenorm(mix_21871);
			t_sample history_3961_next_21876 = fixdenorm(mix_21872);
			t_sample history_3959_next_21873 = fixdenorm(mix_21878);
			t_sample add_3897 = (phasor_4138 + ((t_sample)0.5));
			t_sample wrap_3900 = wrap(add_3897, ((int)0), ((int)1));
			int wave_end_159 = ((lplp_dim > int(chunksiz_3955)) ? int(chunksiz_3955) : lplp_dim);
			int wave_offset_160;
			int wave_len_161;
			if ((wave_end_159 > 0)) {
				wave_offset_160 = 0;
				wave_len_161 = (wave_end_159 - 0);
				
			} else {
				wave_offset_160 = 0;
				wave_len_161 = lplp_dim;
				
			};
			double sample_index_162 = (wrap_3900 * wave_len_161);
			int index_trunc_163 = fixnan(floor(sample_index_162));
			double index_fract_164 = (sample_index_162 - index_trunc_163);
			int index_trunc_165 = (index_trunc_163 - 1);
			int index_trunc_166 = (index_trunc_163 + 1);
			int index_trunc_167 = (index_trunc_163 + 2);
			int index_wrap_168 = ((index_trunc_165 < 0) ? ((wave_len_161 - 1) + ((index_trunc_165 + 1) % wave_len_161)) : (index_trunc_165 % wave_len_161));
			int index_offset_169 = (index_wrap_168 + wave_offset_160);
			int index_wrap_170 = ((index_trunc_163 < 0) ? ((wave_len_161 - 1) + ((index_trunc_163 + 1) % wave_len_161)) : (index_trunc_163 % wave_len_161));
			int index_offset_171 = (index_wrap_170 + wave_offset_160);
			int index_wrap_172 = ((index_trunc_166 < 0) ? ((wave_len_161 - 1) + ((index_trunc_166 + 1) % wave_len_161)) : (index_trunc_166 % wave_len_161));
			int index_offset_173 = (index_wrap_172 + wave_offset_160);
			int index_wrap_174 = ((index_trunc_167 < 0) ? ((wave_len_161 - 1) + ((index_trunc_167 + 1) % wave_len_161)) : (index_trunc_167 % wave_len_161));
			int index_offset_175 = (index_wrap_174 + wave_offset_160);
			// wave lplp channel 1;
			double read_lplp_176 = m_lplp_60.read(index_offset_169, 0);
			double read_lplp_177 = m_lplp_60.read(index_offset_171, 0);
			double read_lplp_178 = m_lplp_60.read(index_offset_173, 0);
			double read_lplp_179 = m_lplp_60.read(index_offset_175, 0);
			double readinterp_180 = spline_interp(index_fract_164, read_lplp_176, read_lplp_177, read_lplp_178, read_lplp_179);
			// wave lplp channel 2;
			double read_lplp_182 = m_lplp_60.read(index_offset_169, chan_clamp_181);
			double read_lplp_183 = m_lplp_60.read(index_offset_171, chan_clamp_181);
			double read_lplp_184 = m_lplp_60.read(index_offset_173, chan_clamp_181);
			double read_lplp_185 = m_lplp_60.read(index_offset_175, chan_clamp_181);
			double readinterp_186 = spline_interp(index_fract_164, read_lplp_182, read_lplp_183, read_lplp_184, read_lplp_185);
			t_sample sample_lplp_4129 = readinterp_180;
			t_sample sample_lplp_4130 = readinterp_186;
			t_sample index_lplp_4131 = sample_index_162;
			t_sample triangle_3898 = triangle(wrap_3900, ((t_sample)0.5));
			t_sample sub_21887 = (triangle_3898 - ((t_sample)0.5));
			int gt_21890 = (sub_21887 > ((int)0));
			t_sample mul_21889 = (sub_21887 * ((int)2));
			t_sample add_21894 = (mul_21889 + ((t_sample)0.5));
			t_sample clamp_21893 = ((add_21894 <= ((int)0)) ? ((int)0) : ((add_21894 >= ((int)1)) ? ((int)1) : add_21894));
			t_sample switch_21888 = (((int)0) ? gt_21890 : clamp_21893);
			t_sample mul_4128 = (sample_lplp_4129 * switch_21888);
			t_sample add_4132 = (mul_4133 + mul_4128);
			t_sample mix_22635 = (add_4132 + (expr_4525 * (selector_4035 - add_4132)));
			__m_slide_187 = fixdenorm((__m_slide_187 + (((gen_3968 > __m_slide_187) ? iup_188 : idown_189) * (gen_3968 - __m_slide_187))));
			t_sample slide_4010 = __m_slide_187;
			t_sample mul_4011 = (slide_4010 * ((t_sample)1.5707963267949));
			t_sample sin_4016 = sin(mul_4011);
			t_sample mul_4014 = (mix_22611 * sin_4016);
			t_sample rsub_4018 = (((int)1) - slide_4010);
			t_sample mul_4012 = (rsub_4018 * ((t_sample)1.5707963267949));
			t_sample sin_4017 = sin(mul_4012);
			t_sample mul_4015 = (mix_22635 * sin_4017);
			t_sample add_4013 = (mul_4015 + mul_4014);
			__m_slide_190 = fixdenorm((__m_slide_190 + (((gen_4090 > __m_slide_190) ? iup_191 : idown_192) * (gen_4090 - __m_slide_190))));
			t_sample slide_21901 = __m_slide_190;
			t_sample mul_21898 = (slide_21901 * ((t_sample)1.5707963267949));
			t_sample sin_21896 = sin(mul_21898);
			t_sample mul_21900 = (add_4013 * sin_21896);
			t_sample rsub_21899 = (((int)1) - slide_21901);
			t_sample mul_21895 = (rsub_21899 * ((t_sample)1.5707963267949));
			t_sample sin_21903 = sin(mul_21895);
			t_sample mul_21897 = (in1 * sin_21903);
			t_sample add_21902 = (mul_21897 + mul_21900);
			t_sample mul_3957 = (add_21902 * gen_4088);
			t_sample mul_3824 = (mul_3957 * ((t_sample)0.5));
			t_sample tanh_3823 = tanh(mul_3824);
			t_sample mul_3822 = (tanh_3823 * ((int)2));
			t_sample dcblock_3818 = __m_dcblock_193(mul_3822);
			t_sample out1 = dcblock_3818;
			t_sample mul_4121 = (sample_lplp_4130 * switch_21888);
			t_sample add_4122 = (mul_4123 + mul_4121);
			t_sample mix_22636 = (add_4122 + (expr_4098 * (selector_4031 - add_4122)));
			__m_slide_194 = fixdenorm((__m_slide_194 + (((gen_3968 > __m_slide_194) ? iup_195 : idown_196) * (gen_3968 - __m_slide_194))));
			t_sample slide_21910 = __m_slide_194;
			t_sample mul_21907 = (slide_21910 * ((t_sample)1.5707963267949));
			t_sample sin_21905 = sin(mul_21907);
			t_sample mul_21909 = (mix_22612 * sin_21905);
			t_sample rsub_21908 = (((int)1) - slide_21910);
			t_sample mul_21904 = (rsub_21908 * ((t_sample)1.5707963267949));
			t_sample sin_21912 = sin(mul_21904);
			t_sample mul_21906 = (mix_22636 * sin_21912);
			t_sample add_21911 = (mul_21906 + mul_21909);
			__m_slide_197 = fixdenorm((__m_slide_197 + (((gen_4090 > __m_slide_197) ? iup_198 : idown_199) * (gen_4090 - __m_slide_197))));
			t_sample slide_21919 = __m_slide_197;
			t_sample mul_21916 = (slide_21919 * ((t_sample)1.5707963267949));
			t_sample sin_21914 = sin(mul_21916);
			t_sample mul_21918 = (add_21911 * sin_21914);
			t_sample rsub_21917 = (((int)1) - slide_21919);
			t_sample mul_21913 = (rsub_21917 * ((t_sample)1.5707963267949));
			t_sample sin_21921 = sin(mul_21913);
			t_sample mul_21915 = (in2 * sin_21921);
			t_sample add_21920 = (mul_21915 + mul_21918);
			t_sample mul_3956 = (add_21920 * gen_4088);
			t_sample mul_3821 = (mul_3956 * ((t_sample)0.5));
			t_sample tanh_3820 = tanh(mul_3821);
			t_sample mul_3819 = (tanh_3820 * ((int)2));
			t_sample dcblock_3817 = __m_dcblock_200(mul_3819);
			t_sample out2 = dcblock_3817;
			m_history_39 = history_3963_next_3965;
			m_history_37 = history_3959_next_3967;
			m_history_38 = history_3961_next_3966;
			m_delay_32.write(prelatch_3906);
			m_delay_27.write(prelatch_3904);
			m_history_26 = history_3963_next_21797;
			m_history_24 = history_3959_next_21793;
			m_history_25 = history_3961_next_21794;
			m_history_23 = history_3963_next_21810;
			m_history_21 = history_3959_next_21805;
			m_history_22 = history_3961_next_21808;
			m_history_20 = history_3963_next_21821;
			m_history_18 = history_3959_next_21822;
			m_history_19 = history_3961_next_21823;
			m_history_9 = history_3976_next_3978;
			m_history_8 = history_3974_next_3979;
			m_p_7 = p_next_3893;
			m_history_6 = history_3963_next_21849;
			m_history_4 = history_3959_next_21851;
			m_history_5 = history_3961_next_21848;
			m_history_3 = history_3963_next_21877;
			m_history_1 = history_3959_next_21873;
			m_history_2 = history_3961_next_21876;
			m_delay_27.step();
			m_delay_32.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			
		};
		return __exception;
		
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_51 = (_value < 0 ? 0 : (_value > 3 ? 3 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_56 = (_value < 0.25 ? 0.25 : (_value > 2.75 ? 2.75 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_vplp(void * _value) {
		m_vplp_58.setbuffer(_value);
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_59 = (_value < 0.25 ? 0.25 : (_value > 2.75 ? 2.75 : _value));
	};
	inline void set_lplp(void * _value) {
		m_lplp_60.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 6;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 13; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_button(value); break;
		case 1: self->set_ctrl1(value); break;
		case 2: self->set_ctrl2(value); break;
		case 3: self->set_ctrl3(value); break;
		case 4: self->set_ctrl4(value); break;
		case 5: self->set_ctrl5(value); break;
		case 6: self->set_ctrl6(value); break;
		case 7: self->set_ctrl7(value); break;
		case 8: self->set_gate(value); break;
		case 9: self->set_lplp(ref); break;
		case 10: self->set_sw1(value); break;
		case 11: self->set_sw2(value); break;
		case 12: self->set_vplp(ref); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_49; break;
		case 1: *value = self->m_ctrl_56; break;
		case 2: *value = self->m_ctrl_59; break;
		case 3: *value = self->m_ctrl_51; break;
		case 4: *value = self->m_ctrl_55; break;
		case 5: *value = self->m_ctrl_54; break;
		case 6: *value = self->m_ctrl_48; break;
		case 7: *value = self->m_ctrl_50; break;
		case 8: *value = self->m_gate_52; break;
		
		case 10: *value = self->m_sw_53; break;
		case 11: *value = self->m_sw_57; break;
		
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(13 * sizeof(ParamInfo));
	self->__commonstate.numparams = 13;
	// initialize parameter 0 ("m_button_49")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_56")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_56;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.25;
	pi->outputmax = 2.75;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_59")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_59;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.25;
	pi->outputmax = 2.75;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_51")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 3;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_ctrl_55")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_55;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_54")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_48")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_50")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_50;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_52")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_52;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_lplp_60")
	pi = self->__commonstate.params + 9;
	pi->name = "lplp";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_53")
	pi = self->__commonstate.params + 10;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_53;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sw_57")
	pi = self->__commonstate.params + 11;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_57;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_vplp_58")
	pi = self->__commonstate.params + 12;
	pi->name = "vplp";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // crcltr1_2egendsp::
