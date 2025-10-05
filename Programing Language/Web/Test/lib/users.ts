import fs from 'fs';
import path from 'path';
import { User } from '@/types';

const usersFilePath = path.join(process.cwd(), 'data', 'users.json');

export function getUserByEmail(email: string): User | undefined {
  try {
    const fileContents = fs.readFileSync(usersFilePath, 'utf8');
    const users: User[] = JSON.parse(fileContents);
    return users.find(user => user.email === email);
  } catch (error) {
    console.error('Error reading users:', error);
    return undefined;
  }
}
