import child_process from 'child_process';
import pad from "launchpad-mini";
import { ScriptDir } from '../Config';
import open from 'open';

export const
    row = "6",
    column = "6",
    color = pad.Colors.green;

export function run()
{
    child_process.exec(`${ScriptDir}/EXE/Clipboard.exe`, (err, stdout, stderr) => {
        const text = stdout.trim();
        open(text);
    });
}