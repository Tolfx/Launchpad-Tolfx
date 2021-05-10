import child_process from 'child_process';
import pad from "launchpad-mini";
import { ScriptDir } from '../Config';

export const
    row = "7",
    column = "7",
    color = pad.Colors.green;

export function run() {
    child_process.spawn(`${ScriptDir}/Batch/OpenDiscord.bat`);
}
