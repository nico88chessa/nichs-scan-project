/*
 * CyclicRunnable.cpp
 *
 *  Created on: 15/feb/2015
 *      Author: nicola
 */

#include "CyclicRunnable.h"

CyclicRunnable::~CyclicRunnable() {
}

void CyclicRunnable::run() {

	doBeforeCycle();

	while (this->hasCycle()) {
		this->doCycle();
	}

	doAfterCycle();
}

void CyclicRunnable::doBeforeCycle() { }

void CyclicRunnable::doAfterCycle() { }
