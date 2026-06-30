import { z } from "zod"

export const createTaskSchema = z.object({
    body: z.object({
        title: z.string()
            .min(3, 'El título debe tener al menos 3 caracteres')
            .max(100, 'El título no puede exceder 100 caracteres'),
        description: z.string().optional(),
        completed: z.boolean().optional().default(false),
        priority: z.enum(["low","medium", "high"]).optional().default("medium"),
    }),
    params: z.object({
        id: z.string().regex(/^\d+$/, 'ID debe ser numérico')
    })
    
})

export const updateTasksSchema = z.object({
    body: z.object({
        title: z.string().min(3).max(100),
        description: z.string().optional(),
        completed: z.boolean().optional(),
        priority: z.enum(["low","medium", "high"]).optional(),
    }),
    params: z.object({
        id: z.string().regex(/^\d+$/, 'ID debe ser numérico')
    })
})