/* Komondor IEEE 802.11ax Simulator
 *
 * Copyright (c) 2017, Universitat Pompeu Fabra.
 * GNU GENERAL PUBLIC LICENSE
 * Version 3, 29 June 2007

 * Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * -----------------------------------------------------------------
 *
 * Author  : Sergio Barrachina-Muñoz and Francesc Wilhelmi
 * Created : 2016-12-05
 * Updated : $Date: 2017/03/20 10:32:36 $
 *           $Revision: 1.0 $
 *
 * -----------------------------------------------------------------
 */

/**
 * action.h: this file defines an action to be used by intelligent agents in Multi-Armed Bandits
 */

#include "../list_of_macros.h"
#include "logger.h"

#ifndef _AUX_ACTION_
#define _AUX_ACTION_

// Action info
struct Action
{

	int id;				///> Action identifier

	// Configuration - Only channel, sensitivity, transmission power and DCB policy are considered at this moment
	int channel;		///> Channel selected
	double cca;			///> CCA level
	double tx_power;	///> Tx Power
	int dcb_policy;		///> DCB policy

	// Full run information
	double instantaneous_reward;
	double cumulative_reward;
	int times_played;

	// Information since last request from the controller
	Performance performance_since_last_request;
	double cumulative_reward_since_last_request;
	int times_played_since_last_request;
	double average_reward_since_last_request;

	/**
	 * Print the action
	 */
	void PrintAction() {
		printf("------------\n Action %d:\n", id);
		printf(" * channel = %d\n", channel);
		printf(" * cca = %f dBm\n", ConvertPower(PW_TO_DBM, cca));
		printf(" * tx_power = %f dBm\n", ConvertPower(PW_TO_DBM, tx_power));
		printf(" * dcb_policy = %d\n", dcb_policy);
		printf("------------\n");
	}

	/**
	 * Write the action to the agent logs file
	 * @param "agent_logger" [type Logger]: logger object
	 * @param "save_agent_logs" [type int]: bool indicating whether to save logs or not
	 * @param "sim_time" [type double]: simulation time
	 * @param "agent_id" [type int]: identifier of the agent writing the logs
	 */
	void WriteAction(Logger agent_logger, int save_agent_logs, double sim_time, int agent_id) {
		LOGS(save_agent_logs, agent_logger.file,
			"%.15f;A%d;%s;%s Action (%d):\n", sim_time, agent_id, LOG_C03, LOG_LVL2, id);
		LOGS(save_agent_logs, agent_logger.file,
			"%.15f;A%d;%s;%s channel = %d\n", sim_time, agent_id, LOG_C03, LOG_LVL3, channel);
		LOGS(save_agent_logs, agent_logger.file,
			"%.15f;A%d;%s;%s cca = %f dBm\n", sim_time, agent_id, LOG_C03, LOG_LVL3, ConvertPower(PW_TO_DBM, cca));
		LOGS(save_agent_logs, agent_logger.file,
			"%.15f;A%d;%s;%s tx_power = %f dBm\n", sim_time, agent_id, LOG_C03, LOG_LVL3, ConvertPower(PW_TO_DBM, tx_power));
		LOGS(save_agent_logs, agent_logger.file,
			"%.15f;A%d;%s;%s dcb_policy = %d\n", sim_time, agent_id, LOG_C03, LOG_LVL3, dcb_policy);
	}

	/**
	 * Print the performance of the action
	 */
	void PrintRewardInformation() {
		printf("------------\n Reward information (a%d):\n", id);
		printf(" * instantaneous_reward = %f\n", instantaneous_reward);
		printf(" * cumulative_reward = %f\n", cumulative_reward);
		printf(" * times_played = %d\n", times_played);
		printf("------------\n");
	}

	/**
	 * Print the performance of the action
	 */
	void PrintControllerStatistics() {
		printf("------------\n Information since last CC request (a%d):\n", id);
		printf(" * cumulative_reward_since_last_request = %f\n", cumulative_reward_since_last_request);
		printf(" * times_played_since_last_request = %d\n", times_played_since_last_request);
		printf(" * average_reward_since_last_request = %f\n", average_reward_since_last_request);
		printf("------------\n");
	}

};

#endif
