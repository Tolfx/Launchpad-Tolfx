import child_process from 'child_process';
import pad from "launchpad-mini";
import { ScriptDir } from '../Config';

export const
    row = "6",
    column = "5",
    color = pad.Colors.green;

export function run() {
    child_process.exec(`${ScriptDir}/Batch/Open.bat https://webmail.tolfix.com/`);
}
