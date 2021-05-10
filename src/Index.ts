#!/usr/bin/env node

import Launchpad from 'launchpad-mini';
import Connect from './Handler/Connect';
import Disconnet from './Handler/Disconnet';
import Key from './Handler/Key';

let pad = new Launchpad();

Connect(pad);
Disconnet(pad);
Key(pad);