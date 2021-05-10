import child_process from 'child_process';
import pad from "launchpad-mini";
import { ScriptDir } from '../Config';

export const row = "6";
export const column = "7";
export const color = pad.Colors.green;

export function run()
{
    child_process.spawn(`${ScriptDir}/Batch/OpenGoogle.bat`);
}